#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >>s;
  string t[4];
  t[0]="SS";t[1]="SW";t[2]="WS";t[3]="WW";
  int flag=0;
  rep(i,4){  
    string ans;
    ans=t[i];
    rep1(i,n-2){
      if((ans[i]=='S' && s[i]=='o') || (ans[i]=='W' && s[i]=='x')){
	ans.pb(ans[i-1]);
      }
      else{
	if(ans[i-1]=='S') ans.pb('W');
	else ans.pb('S');
      }
    }
    if((ans[n-1]=='S' && s[n-1]=='o') || (ans[n-1]=='W' && s[n-1]=='x')){
      if(ans[0]==ans[n-2]) flag=1;
    }
    else{
      if(ans[n-2]!=ans[0]) flag=1;
    }
    if(flag){
      if((ans[0]=='S' && s[0]=='o') || (ans[0]=='W' && s[0]=='x')){
	if(ans[1]==ans[n-1]) flag=2;
      }
      else{
	if(ans[n-1]!=ans[1]) flag=2;
      }
    }
    if(flag==2){
      rep(i,n)cout << ans[i];
      cout << "" << endl;
      break;
    }
    flag=0;
  }
  if(flag!=2) cout << -1 << endl;
  
  return 0;
  

}
