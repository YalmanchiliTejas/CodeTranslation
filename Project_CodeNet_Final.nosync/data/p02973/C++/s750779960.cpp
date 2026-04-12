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
#include <iomanip>

using namespace std;

int main() {
    
    
    int n;
    cin >> n;
    vector<int> a(n, -1);
    
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        *upper_bound(a.begin(), a.end(), tmp, greater<>()) = tmp;
    }
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != -1)
        {
            ret++;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}