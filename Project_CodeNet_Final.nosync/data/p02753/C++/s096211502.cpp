#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 1e5 + 100;
ll s[maxn][8];
ll cum[maxn];
vector < pair < ll , ll > > arr;
ll dp[maxn][8];
ll n , p , k;

ll solve(int i , int d){
    if(d == p){
        ll nei = abs(i-d+1);
        ll d = n - (p+k);
        if(nei>d)
            return (-1e18);
        ll hm = abs(nei-d);
        cout << i << " " << d << " " << p << endl;
        return cum[n-1]-cum[i+hm-1];
    }
    if(i == n){
        return (-1e18);
    }
    ll &ret = dp[i][d];
    if(ret != -1)return ret;
    ret = max( s[arr[i].second][d] + solve(i+1,d+1) , solve(i+1,d) );
    return ret;
}

int main()
{
    ll n, m, k, a = 0, b = 0;
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') a = 1;
        if(s[i] == 'B') b = 1;
    }
    if(a && b) puts("Yes");
    else puts("No");
    return 0;
}
