#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;

const int root = -1;
unordered_map <int, vector<int>> Successors;
unordered_map <int, int> Cache;

int get_max_depth (int max_depth, int person) {
    if (!Cache[person]) {
        auto &S = Successors[person];
        Cache[person] = 1 + accumulate (begin(S), end(S), 0, get_max_depth);
    }
    return max (max_depth, Cache[person]);
}

void CheckMain() {
    // the number of relationships of influence
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        // a relationship of influence between two people (x influences y)
        int x, y; cin >> x >> y;
        Successors[root].push_back(x);
        Successors[x].push_back(y);
    }
    // The number of people involved in the longest succession of influence
    cout << get_max_depth(0, root) - 1 << endl;
}
