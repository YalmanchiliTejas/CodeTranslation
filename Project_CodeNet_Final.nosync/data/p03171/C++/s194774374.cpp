#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo 1e18
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const long double Pi=acos(-1),e=2.718;
const int N=3e3+10,mod=1e9+7;
ll n,a[N],dp1[N][N][2],k,dp2[N][N][2];
ll solve1(int L,int R,bool T){
    if(L>R)return 0;
    ll &ret=dp1[L][R][T];
    if(ret+1)return ret;
    if(T){
        ret = min(solve1(L,R-1,!T),solve1(L+1,R,!T));
    }
    else{
        ret = max(solve1(L,R-1,!T)+a[R],solve1(L+1,R,!T)+a[L]);
    }
    return ret;
}
ll solve2(int L,int R,bool T){
    if(L>R)return 0;
    ll &ret=dp2[L][R][T];
    if(ret+1)return ret;
    if(!T){
        ret = min(solve2(L,R-1,!T),solve2(L+1,R,!T));
    }
    else{
        ret = max(solve2(L,R-1,!T)+a[R],solve2(L+1,R,!T)+a[L]);
    }
    return ret;
}
int main()
{
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);

    FASTIO
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << solve1(0,n-1,0)-solve2(0,n-1,0) << endl;
    return 0;
}
/**

*/
