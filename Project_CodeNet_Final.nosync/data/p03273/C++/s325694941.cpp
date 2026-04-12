#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
string s[111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w;cin>>h>>w;
  for(int i=0;i<h;i++)cin>>s[i];
  for(int i=0;i<h;i++){
    ll cnt = 0;
    for(int j=0;j<w;j++){
      bool fl2 = true;
      for(int k=0;k<h;k++){
	if(s[k][j] == '#')fl2 = false;
      }
      bool fl = true;
      for(int k=0;k<w;k++){
	if(s[i][k] == '#')fl = false;
      }
      if(fl == false && fl2 == false){cnt++;cout<<s[i][j];}
    }
    if(cnt)
      cout<<endl;
  }
  return 0;
}
