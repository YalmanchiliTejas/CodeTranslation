#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,k;
char s[20];
char res[20];
void solve(){
  char key=s[k-1];
  rep(i,n){
    if(s[i]==key){
      res[i]=s[i];
    }
    else{
      res[i]='*';
    }
  }
  rep(i,n){
    cout<<res[i];
  }
  cout<<"\n";
}
int main(){
  cin>>n;
  rep(i,n) cin>>s[i];
  cin>>k;
  solve();
  return 0;
}
