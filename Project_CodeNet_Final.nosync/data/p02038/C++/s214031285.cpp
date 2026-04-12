#include<bits/stdc++.h>
using namespace std;
int n;
bool t[100005];

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    char ch;
    cin>>ch;
    t[i]=(ch=='T');
  }
  bool res=t[0];
  for(int i=1;i<n;i++){
    res= ( !res || t[i] );
  }
  if( res )cout<<'T'<<endl;
  else cout<<'F'<<endl;
  return 0;
}

