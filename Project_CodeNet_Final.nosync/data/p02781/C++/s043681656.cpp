/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 110
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};


//=============================================ASIFAZAD==============================================
string num;
int k, n;
ll dp[120][5][2];

ll dig_dp(int pos, int cnt, int sm)
{
    if(pos == n)
        return cnt==k;
    if(cnt > k)
        return 0;
    if(dp[pos][cnt][sm] != -1)
        return dp[pos][cnt][sm];
    int lim = (sm?9:(int)(num[pos] - '0'));
    ll res = 0;
    for(int i = 0; i<= lim; i++)
    {
        int nsm = sm;
        if(i < lim)
            nsm = 1;
        int ncnt = (i?cnt + 1:cnt);
        res += dig_dp(pos + 1, ncnt, nsm);
    }
    return dp[pos][cnt][sm] = res;
}


int32_t main()
{
    io;
    cin>>num>>k;
    n = num.size();
    memset(dp, -1, sizeof(dp));
    cout<<dig_dp(0, 0, 0);
    return 0;
}
