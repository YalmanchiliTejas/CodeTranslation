#include<bits/stdc++.h>

using namespace std;
#define taskname "TEST"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
string s;

int dp[maxn][101][2] , d;
int cal(int pos , int m , bool pre)
{
    if(pos == s.size())return m == 0;
    int & res = dp[pos][m][pre];
    if(res != -1)return res;
    res = 0;
    int lim = (pre == 1 ? 9 : s[pos] - '0');
    for(int i = 0 ; i <= lim ; ++i)
    {
        res += cal(pos + 1 , (m + i) % d , pre | (i < lim));
        if(res >= mod)res -= mod;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(taskname".INP","r"))
        freopen(taskname".INP", "r",stdin) ,
        freopen(taskname".OUT", "w",stdout);
    fill_n(&dp[0][0][0],maxn*101*2,-1);
    cin >> s >> d;
    cout << (cal(0,0,0) - 1 + mod) % mod;
}
