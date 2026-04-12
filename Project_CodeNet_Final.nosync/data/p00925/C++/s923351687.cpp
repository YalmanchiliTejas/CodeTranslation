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
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int to_int(char ch) { return ch - '0'; }
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int val; cin >> val;
    int L = to_int(s[0]);
    for(int i = 1; i < s.size(); i += 2)
    {
        if(s[i] == '+') L += to_int(s[i + 1]);
        if(s[i] == '*') L *= to_int(s[i + 1]);
    }
    vector<int> v;
    for(int i = 1; i < s.size(); i += 2)
    {
        int tmp = to_int(s[i - 1]);
        while(s[i] == '*')
        {
            tmp *= to_int(s[i + 1]);
            i += 2;
        }
        v.push_back(tmp);
    }
    if(s[s.size() - 2] == '+' || s.size() == 1) v.push_back(to_int(s.back()));
    int M = 0;
    for(int i = 0; i < v.size(); i++) M += v[i];
    // for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
    // cout << L << " " << M << endl;
    if(val == L && val == M) cout << "U" << endl;
    else if(val == L) cout << "L" << endl;
    else if(val == M) cout << "M" << endl;
    else cout << "I" << endl;
    return 0;
}


