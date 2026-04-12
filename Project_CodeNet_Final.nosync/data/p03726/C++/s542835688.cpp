#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<set<int> > edges(n);
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        -- a;
        -- b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    queue<int> leaf;
    for(int i=0; i<n; ++i){
        if(edges[i].size() == 1)
            leaf.push(i);
    }

    while(!leaf.empty()){
        int a = *edges[leaf.front()].begin();
        leaf.pop();

        int cnt = 0;
        for(int b : edges[a]){
            if(edges[b].size() == 1)
                ++ cnt;
            edges[b].erase(a);
            if(edges[b].size() == 1)
                leaf.push(b);
        }

        if(cnt >= 2){
            cout << "First" << endl;
            return 0;
        }
    }

    cout << "Second" << endl;
    return 0;
}
