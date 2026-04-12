#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,x,m,ans,loopans,ac,jdg;cin >> n >> x >> m;
  ans=x;ac=x;loopans=0;jdg=0;
  vector<long long> a(m,0),loopcount(3,0);
  
  for (long long i=1;i<n;i++) {
    ac=ac*ac%m;
	if (a[ac]==0) {a[ac]=i;ans+=ac;}
	else {
	  loopcount[1]=i;
	  loopcount[2]=i-a[ac];
	  break;
	}
  }
  if (loopcount[1]==0) cout << ans << endl;
  else{
  
  for (long long i=0;i<loopcount[2];i++) {
    if (loopcount[1]+i>n-1) {
	  jdg=1;
	  break;
	}
	loopans+=ac;
	ac=ac*ac%m;
  }
  if (jdg==1) cout << ans+loopans << endl;
  else {
    ans+=((((n-loopcount[1])/loopcount[2]))*(loopans));
	loopans=0;
	for (long long i=0;i<(n-loopcount[1])%loopcount[2];i++) {     
	  loopans+=ac;
	  ac=ac*ac%m;
    }
	cout << ans+loopans << endl;
  } 
  }
}