#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int bit = 0; bit < (1<<n); bit++)
    {
        vector<int> v;
        //cout << (bitset<8>(bit)) << endl;
        for(int i = 0; i < n; i++)
        {
            if(bit & (1<<i)) v.push_back(i);
        }
        cout << bit << ":";
        for(int i = 0; i < v.size(); i++) cout << " " << v[i];
        cout << endl;
    }
    return 0;
}
