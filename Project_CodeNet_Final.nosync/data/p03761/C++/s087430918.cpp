#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++) 
#define rep(i,n); for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b); 
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e10+10;

/*----------------------------------------------*/
int check[30][52];

signed main(){
  int n;
  cin>>n;
  string s[50];
  rep(i,n) cin>>s[i];
  rep(i,n){
    rep(j,s[i].size()){
      int k=s[i][j]-'a';
      check[k][i]++;
    }
  }
  string ans;
  rep(i,26){
    int t=50;
    rep(j,n) chmin(t,check[i][j]);
    rep(_,t) ans.push_back('a'+i);
  }
  cout<<ans<<endl;
  return 0;
}