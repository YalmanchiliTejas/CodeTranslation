#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std; 
int main(){
  string s;  
  while(cin>>s&&s!="#"){  
int n=s.size();
    int a[50];    
    for(int i=0;i<n;i++){
      if(s[i]=='y'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='p'||s[i]=='h'||s[i]=='j'||s[i]=='k'||s[i]=='l'||s[i]=='n'||s[i]=='m'){
	a[i]=0;
      }else{
	a[i]=1;
      }
    }
  
    int ans=0;
    for(int i=0;i<n-1;i++){
      if(a[i]==a[i+1]){
	continue;
      }else ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
 
}