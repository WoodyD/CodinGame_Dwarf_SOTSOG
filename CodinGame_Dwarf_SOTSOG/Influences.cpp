#include "Influences.hpp"

// ?? change private members of parrent class ??
//namespace {
//    void ResetInfluences()
//    {
//        for(auto & inf : Influences::infs)
//        {
//            inf.steps = 1;
//            inf.used = false;
//        }
//    }
//}

Influences& Influences::AddInfluence(int x, int y)
{
    Influence inf{x, y};
    infs.push_back(inf);
    return *this;
}

int Influences::GetLongestInfluenceChain() 
{
    for(int & infl : firstInfluencers())
    {
        ResetInfluences();
        DSFRecursive(infl);
    }
    return longestInfChain;
}

std::vector<int> Influences::firstInfluencers()
{
    std::vector<int> toReturn;
    for(auto & infX : infs)
    {
        for(auto & infY : infs)
        {
            if(infX.x == infY.y)
            {
                infX.used = true;
                break;
            }
        }
        
        if(!infX.used)
            toReturn.push_back(infX.x);
    }
    
    return toReturn;
}

void Influences::DSFRecursive(const int influencer, const int steps)
{
    std::cout << "Check influencer: " << influencer << std::endl;
    std::cout << "Influencer steps: " << steps << std::endl;
    for(auto & checkInf : infs)
    {
        if(checkInf.x == influencer && !checkInf.used)
        {
            checkInf.used = true;
            checkInf.steps = steps + 1;
                
            if(longestInfChain < checkInf.steps)
                longestInfChain = checkInf.steps;
                
            DSFRecursive(checkInf.y, checkInf.steps);
        }
    }
}

void Influences::ResetInfluences()
{
    for(auto & inf : infs)
    {
        inf.steps = 1;
        inf.used = false;
    }
}



