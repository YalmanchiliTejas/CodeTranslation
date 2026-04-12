// 怪文書
// #17080666
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)
 
typedef long long ll;
using namespace std;
int main()
{
  ll n;
  string s[100];
  ll cnt[26];
  cin>>n;
  rep(i,n){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
  }
  ll min;
  for(char l='a';l<='z';l++){
    min=1000000;
    rep(i,n){
      ll tmp=0;
      rep(j,s[i].length()){
        if(s[i][j]==l)tmp++;
      }
      if(tmp<min)min=tmp;
    }
    cnt[l-'a']=min;
  }
 
  rep(i,26){
    rep(j,cnt[i]){
      printf("%c",'a'+i);
    }
  }
 
  cout<<endl;
 
  return 0;
}