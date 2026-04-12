
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;


int main(){
  int n;
  string s[50];
  cin>>n;
  int cnt[26],cnt2[26];
  rep(i,26){
    cnt[i]=0;
    cnt2[i]=BIG;
  }
  rep(i,n){
    cin>>s[i];
  }
  rep(i,n){
    rep(j,s[i].size() ){
      cnt[s[i][j]-97]++;
    }
   
    rep(j,26){
      cnt2[j]=min(cnt2[j],cnt[j]);
      cnt[j]=0;
    }
    // cout<<cnt2[0]<<" "<<cnt2[1]<<" "<<cnt2[2]<<" "<<cnt2[3];
  }
  rep(i,26){
    while(cnt2[i]!=0){
      char c=i+97;
      cout<<c;
      cnt2[i]--;
    }
  }
  cout<<endl;
  return 0;
}
