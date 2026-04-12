#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w;cin>>h>>w;
  string MP[h];
  for(int i=0;i<h;i++)
    cin>>MP[i];
  for(int i=0;i<h;i++){
    bool kai=true;
    for(int j=0;j<w;j++){
      bool can=true,can2=true;
      for(int ii=0;ii<h;ii++){
	if(MP[ii][j]=='#')can=false;
      }
      for(int jj=0;jj<w;jj++){
	if(MP[i][jj]=='#')can2=false;
      }
      if(!(can||can2)){
	cout<<MP[i][j];kai=false;
      }
    }
    if(kai==false)
      cout<<endl;
  }
  return 0;
}
