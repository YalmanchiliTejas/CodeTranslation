#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  vector<vector<ll>> a(s.size()+1,vector<ll>(k+1,0)),b(s.size()+1,vector<ll>(k+1,0));
  b[0][0]=1;
  rep(i,s.size()){
      rep(j,k+1){
          ll u=s[i]-'0';
          a[i+1][j]+=a[i][j];
          if (u!=0) a[i+1][j]+=b[i][j];
          if (u==0) b[i+1][j]+=b[i][j];
          if (j!=k){
              a[i+1][j+1]+=a[i][j]*9;
              if (u!=0) a[i+1][j+1]+=b[i][j]*(u-1);
              if (u!=0) b[i+1][j+1]+=b[i][j];
          }
      }
  }
  cout << a[s.size()][k]+b[s.size()][k] << endl;
}
