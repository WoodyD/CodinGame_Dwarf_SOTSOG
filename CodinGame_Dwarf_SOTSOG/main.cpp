#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Influences.hpp"

int main()
{
    Influences infs;
//    int n; // the number of relationships of influence
//    std::cin >> n; std::cin.ignore();
//    for (int i = 0; i < n; i++) {
//        int x; // a relationship of influence between two people (x influences y)
//        int y;
//        std::cin >> x >> y; std::cin.ignore();
//        infs.AddInfluence(x, y);
//    }
    
    //Test cases
    Influences infs1;
    infs1.AddInfluence(1, 2)
        .AddInfluence(1, 3)
        .AddInfluence(3, 4);
    std::cout << "Test case 1 results: " << std::endl;
    std::cout << infs1.GetLongestInfluenceChain() << std::endl;
    
    Influences infs2;
    infs2.AddInfluence(1, 2)
        .AddInfluence(1, 3)
        .AddInfluence(3, 4)
        .AddInfluence(2, 4)
        .AddInfluence(2, 5)
        .AddInfluence(10, 11)
        .AddInfluence(10, 1)
        .AddInfluence(10, 3);
    std::cout << "Test case 2 results: " << std::endl;
    std::cout << infs2.GetLongestInfluenceChain() << std::endl;
    
    std::cout << std::to_string(infs.GetLongestInfluenceChain()) << std::endl;
    
}
