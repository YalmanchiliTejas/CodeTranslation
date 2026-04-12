#include<bits/stdc++.h>
#define rep(X,Y) for(int X=0;X<(Y); ++X)
#define pb push_back
#define eb emplace_back

using namespace std;

typedef long long ll;

string fun(string s){
  string re;
  for(char c:s)
    if(c=='b') re+=c;
    else re+=string(c-'0','.');
  return re;
}

string zip(string s){
  string re;
  int cnt=0;
  for(char c:s){
    if(c=='.'){
      ++cnt;
    }else{
      if(cnt) re+=char('0'+cnt);
      re+='b';
      cnt=0;
    }
  }
  if(cnt) re+=char('0'+cnt);
  return re;
}

int main(){
  string s;
  while(cin>>s, s!="#"){
    s+='/';
    int n=s.size();
    int x,y,X,Y;
    cin>>y>>x>>Y>>X; --x; --y; --X; --Y;
    vector<string> mp;
    string tmp;
    for(char c:s){
      if(c=='/'){
	mp.pb(fun(tmp));
	tmp="";
      }else{
	tmp+=c;
      }
    }
    //for(string s:mp) cout<<s<<endl;
    mp[y][x]='.';
    mp[Y][X]='b';
    rep(i,mp.size()) cout<<zip(mp[i])<<"/\n"[i+1==mp.size()];
  }
  return 0;
}