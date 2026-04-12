#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  string n;
  int k;
  cin>>n>>k;
  int ans=0;
  if(k==1){
    rep(i,n.size()){
      string s(n.size(),'0');
      rep(j,9){
	s[i]='0'+j+1;
	if(s<=n) ans++;
      }
    }
  }
  if(k==2){
    rep(i,n.size()){
      for(int j=i+1;j<n.size();j++){
	string s(n.size(),'0');
	rep(m,9){
	  s[i]='0'+m+1;
	  rep(o,9){
	    s[j]='0'+o+1;
	    if(s<=n) ans++;
	  }
	}
      }
    }
  }
  if(k==3){
    rep(i,n.size()){
      for(int j=i+1;j<n.size();j++){
	for(int l=j+1;l<n.size();l++){
	  string s(n.size(),'0');
	  rep(m,9){
	    s[i]='0'+m+1;
	    rep(o,9){
	      s[j]='0'+o+1;
	      rep(p,9){
		s[l]='0'+p+1;
		if(s<=n) ans++;
	      }
	    }
	  }
	}
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}