#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >>n;
  vector<int> d(n);
  for(int i=0;i<n;++i) cin>>d[i];

  vector<int> st(n);
  vector<int> go(n);
  st[0]=1; go[n-1]=1;
  for(int i=0;i<n;++i){
    if(st[i])
      for(int j=d[i]/10;j>0;--j)
	if(i+j<n) {
	  if(st[i+j]) break;
	  st[i+j]=1;
	}
    if(go[n-(i+1)])
      for(int j=d[n-(i+1)]/10;j>0;--j)
	if(n-(i+j+1)>=0){
	  if(go[n-(i+j+1)]) break;
	  go[n-(i+j+1)]=1;
	}
    if(st[n-1] && go[0]) break;
  }
  
  if(st[n-1] && go[0]) cout << "yes";
  else cout << "no";
  cout <<endl;
  
  return 0;
}

