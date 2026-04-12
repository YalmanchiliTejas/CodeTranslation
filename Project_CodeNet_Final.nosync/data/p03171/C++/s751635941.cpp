#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define INF 10000000000000LL
#define DIM 100007
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> myset;
typedef  pair< long long, pair<long long, long long> > ppll;
ll n,m,c,x,x2,y2,e,h,k,res1,a1,a2,w,a3,y,z,a4,a5,a6,last,dist,LL,timer,start,finish,maxmask,newmax,reslast,tests,police,brothers;
string s,s1;
ld res;
ll dp[3007][3007];
ll mas[3007];
ll l,r;
int main(){


    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mas[i];
    }
    for(int i=1;i<=n;i++){
        //if(n%2==1)mas[i]*=-1;
        dp[1][i]=mas[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            l=j;
            r=j+i-1;
            //if((n-i)%2==0)
            dp[i][j]=max(mas[r]-dp[i-1][j],mas[l]-dp[i-1][j+1]);
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            //else
            //dp[i][j]=max(+dp[i-1][j]-mas[r],+dp[i-1][j+1]-mas[l]);

        }
    }
    cout<<dp[n][1]<<endl;
}
