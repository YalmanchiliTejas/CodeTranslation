#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <fstream>

using namespace std;

int main() {
    
    
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    int m = -1;
    int ret = 0;
    
    for (int i = 0; i < n; ++i)
    {
        if (m <= h[i])
        {
            ret++;
            m = h[i];
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
