#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define mod 1000000007
#define pb push_back
 
typedef long long ll;

using namespace std;

int main(){
  map<char,int> cnt,temp;
  int n;
  for(char c='a'; c<='z'; c++){
    cnt[c]=0;
    temp[c]=0;
  }
  cin >> n ;
  string s,ans="";
  rep(i,n){
    cin >> s;
    if(i==0){
     rep(j,s.size())  cnt[s[j]]++;
    }else{
      for(char c='a'; c<='z'; c++)  temp[c]=0;
      rep(j,s.size()) temp[s[j]]++;
      for(char c='a'; c<='z'; c++){
        cnt[c]=min(cnt[c],temp[c]);
      }
    }
  }
  for(char c='a'; c<='z'; c++){
    if(cnt[c]>0){
      rep(i,cnt[c]) ans.push_back(c);
    }
  }
  cout << ans << endl;
  return 0;
}