#pragma once

#include <vector>
#include <iostream>

class Influences{
public:
    Influences() {};
    Influences& AddInfluence(int x, int y);
    int GetLongestInfluenceChain();
    
private:
    struct Influence{
        int x, y;
        int steps = 1;
        bool used = false;
        Influence(int x, int y) : x(x), y(y) { };
    };
    
    std::vector<Influence> infs;
    int longestInfChain = 0;
    std::vector<int> firstInfluencers();
    void DSFRecursive(const int influencer, const int steps = 1);
    void ResetInfluences();
    
};
