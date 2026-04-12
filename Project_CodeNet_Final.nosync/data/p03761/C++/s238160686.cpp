#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  string s[n];
  rep(i,0,n) cin>>s[i];
  int a[n][26];
  rep(i,0,n){
    rep(j,0,26){
      a[i][j]=0;
    }
  }
  rep(i,0,n){
    for(char c:s[i]){
      a[i][c-'a']++;
    }
  }
  int b[26];
  rep(i,0,26) b[i]=810;
  rep(i,0,n){
    rep(j,0,26){
      b[j]=min(b[j],a[i][j]);
    }
  }
  string t;
  rep(i,0,26){
    rep(j,0,b[i]){
      t+='a'+i;
    }
  }
  cout<<t<<endl;
}