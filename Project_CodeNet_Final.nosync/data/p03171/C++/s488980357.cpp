#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
#define int long long int
using namespace std;
vector<int>arr;
vector<vector<int>>Q[2];
int dp(int l,int r,bool a){
      if(l>r)return Q[a][l][r]=0;
      int A,B;
      if(Q[a^1][l+1][r]==INF)Q[a^1][l+1][r]=dp(l+1,r,a^1);
      if(Q[a^1][l][r-1]==INF)Q[a^1][l][r-1]=dp(l,r-1,a^1);
      A=Q[a^1][l+1][r];
      B=Q[a^1][l][r-1];
      if(a)return max(A+arr[l],B+arr[r]);
      else return min(A-arr[l],B-arr[r]);
}
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   //   freopen("q.gir","r",stdin);
   //   freopen("q.cik","w",stdout);
      int n;
      cin>>n;
      arr.pb(-INF);
      for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            arr.pb(x);
      }
      Q[0].resize(4000,vector<int>(4000,INF));
      Q[1].resize(4000,vector<int>(4000,INF));
      cout<<dp(1,n,1);
}
