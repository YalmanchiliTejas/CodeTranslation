#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

string s;
int n;
string ans;

char notchar(char now){
  if(now == 'S') return 'W';
  else return 'S';
}

char next(char prepre,char pre,char now){
  if(pre == 'S'){
    if(now == 'o') return prepre;
    else return notchar(prepre);
  } else {
    if(now == 'o') return notchar(prepre);
    else return prepre;
  }
}

bool check(string ans){
  bool prev;
  if(ans[n-1] == 'S'){
    if(s[n-1] == 'o'){
      prev = (ans[0] == ans[n-2]);
    } else {
      prev = (ans[0] != ans[n-2]);
    }
  } else {
    if(s[n-1] == 'o'){
      prev = (ans[0] != ans[n-2]);
    } else {
      prev = (ans[0] == ans[n-2]);
    }
  }

  bool now;
  if(ans[0] == 'S'){
    if(s[0] == 'o'){
      now = (ans[1] == ans[n-1]);
    } else {
      now = (ans[1] != ans[n-1]);
    }
  } else {
    if(s[0] == 'o'){
      now = (ans[1] != ans[n-1]);
    } else {
      now = (ans[1] == ans[n-1]);
    }
  }

  return now & prev;

}

int main(){
  cin>>n>>s;

  ans = "SS";
  for(int i=1;i<n-1;i++){
    ans += next(ans[i-1],ans[i],s[i]);
  }
  if(check(ans)){
    cout<<ans<<endl;
    return 0;
  }

  ans = "SW";
  for(int i=1;i<n-1;i++){
    ans += next(ans[i-1],ans[i],s[i]);
  }
  if(check(ans)){
    cout<<ans<<endl;
    return 0;
  }

  ans = "WS";
  for(int i=1;i<n-1;i++){
    ans += next(ans[i-1],ans[i],s[i]);
  }
  if(check(ans)){
    cout<<ans<<endl;
    return 0;
  }

  ans = "WW";
  for(int i=1;i<n-1;i++){
    ans += next(ans[i-1],ans[i],s[i]);
  }
  if(check(ans)){
    cout<<ans<<endl;
    return 0;
  }

  cout<<"-1"<<endl;
  return 0;
}
