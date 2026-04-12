#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  string x[a];
  for(int i=0;i<a;i++) cin>>x[i];
  bool r[a]={},c[b]={};
  for(int i=0;i<a;i++){
    for(int k=0;k<b;k++){
  if(x[i][k]=='#') r[i]=true,c[k]=true;
    }
  }
  for(int i=0;i<a;i++){
  if(r[i]) {
    for(int k=0;k<b;k++){
    if(c[k]) cout<<x[i][k];
    	}
   cout<< endl;
	  }
  	}
}