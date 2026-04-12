#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int n;
  cin>>n;
  vector<string> s(n);
  map<char,int> mp;
  REP(i,n){
    cin>>s[i];
    map<char,int> temp;
    if(i==0){
      for(char c:s[i]){
        mp[c]++;
      }
    }else{
      for(char c:s[i]){
        temp[c]++;
      }
      for(char c='a';c<='z';c++){
        mp[c]=min(mp[c],temp[c]);
      }
    }
  }
  for(char c='a';c<='z';c++){
    REP(i,mp[c]){
      cout<<c;
    }
  }
  cout<<endl;
  
  return 0;
}