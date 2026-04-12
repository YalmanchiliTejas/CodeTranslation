#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// const int MOD = 1000000007;
// const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
    int n;
    cin >> n;
    vector<string> S(n);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        S[i] = s;
    }
    for(int i = 0; i < 26; i++)
    {
        int count = 1000;
        for(int j = 0; j < n; j++)
        {
            int num = 0;
            for(int k = 0; k < S[j].size(); k++)
            {
                if(S[j][k] == 'a' + i) num++;
            }
            count = min(count,num);
        }
        char a = 'a' + i;
        for(int e = 0; e < count; e++)
        {
            cout << a;
        }
    }
    cout << endl;

}