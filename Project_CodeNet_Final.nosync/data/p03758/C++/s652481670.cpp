#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  string s(n,'0');
  int a[n-1],b[n-1],c=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      string t=s;
      t[i]=t[j]='1';
      cout<<"? "<<t<<endl;
      int d;
      cin>>d;
      if(d){
	a[c]=i;
	b[c]=j;
	c++;
      }
    }
  }
  cout<<"!";
  for(int i=0;i<n-1;i++) cout<<" ("<<a[i]<<","<<b[i]<<")";
  cout<<endl;
  return 0;
}
