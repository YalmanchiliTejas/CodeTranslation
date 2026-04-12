#include<bits/stdc++.h>
using namespace std;
int main (){
  
  string n;
  char s[10];
  int l,k,i;
  
  cin>>l; cin>>n; cin>>k;
  
  for (i=0; i<l;i++){
      if (n[i]==n[k-1]) s[i]=n[i];
      else s[i]='*';

  }
     for (i=0; i<l;i++){cout<<s[i];
  }
    
return 0;
}