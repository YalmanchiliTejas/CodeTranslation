#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define LSB __builtin_ctzll
#define sc(a) scanf("%d",&a)
#define MSB 63-__builtin_clzll
#define scl(a) scanf("%lld",&a)
#define BITS __builtin_popcountll
#define mem(a , v)  memset(a , v , sizeof(a))
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 1e9+7;
const int MAX = 1e5+55;
const int INF = 1e9+77;
const ll INFINF = 1e18+1e17;
const double PI = acos(-1.0);
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

ll power(ll x,ll y){
         if(y==0)
         return 1;
         ll s=power(x,y/2);
         s*=s;
         if(y&1)
         s*=x;
         return s;
}



ll dp[3001][3001][2];
ll x[3001];

ll solve(int i,int j,int st){
         if(i>j){
            return 0;
         }

         ll &res=dp[i][j][st];
         if(res!=-1){
            return res;
         }


         if(st){
            res=max(solve(i,j-1,0)+x[j],solve(i+1,j,0)+x[i]);
         }
         else{
            res=min(solve(i,j-1,1),solve(i+1,j,1));
         }

         return res;
}





int main(){

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//freopen("input.txt" , "r" , stdin);
//freopen("output.txt" , "w" , stdout);





    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        sum+=x[i];
    }

    mem(dp,-1);

    cout<<solve(0,n-1,1)-(sum-solve(0,n-1,1));






     return 0;

}
