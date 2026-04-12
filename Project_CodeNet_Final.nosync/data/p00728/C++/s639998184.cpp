#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,s[100],ans=0,tmp;
  while(1){
    ans=0;
    cin>>n;
    if(n==0) break;
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
    for(int i=0;i<n;i++){
      for(int j=n-1;i<j;j--){
	if(s[j]>s[j-1]){
	  tmp=s[j-1];
	  s[j-1]=s[j];
	  s[j]=tmp;
	}
      }
    }
    for(int i=1;i<n-1;i++){
      ans+=s[i];
    }
    ans/=(n-2);
    cout<<ans<<endl;
  }
return 0;
}

