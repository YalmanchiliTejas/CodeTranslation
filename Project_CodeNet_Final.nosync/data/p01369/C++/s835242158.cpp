#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

void solve(){
}

int main(){
  string s;
  string left = "qwertasdfgzxcvb";

  while(cin>>s,s!="#"){
    int now = -1; //0:left 1:right
    int cnt = 0;

    rep(i,s.length()){
      int next = (left.find(s[i]) == string::npos);
      if(now != -1 && now != next){
        cnt++;
      }
      now = next;
    }
    cout<<cnt<<endl;
  }
}