#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  INT(N);
  string s;
  cin >> s;
  int flag = 0;
  vector<char> ans(N);
  ans[0]='S';
  ans[1]='S';
  FOR(i,2,N){
    if(ans[i-1]=='S'&&s[i-1]=='o'){
      ans[i]=ans[i-2];
    }else if(ans[i-1]=='S'&&s[i-1]=='x'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else if(ans[i-1]=='W'&&s[i-1]=='o'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else{
      ans[i]=ans[i-2];
    }
  }
  int flag2 = -1;
  if((ans[N-1]=='S'&&s[N-1]=='o')||(ans[N-1]=='W'&&s[N-1]=='x')){
    flag2=0;
  }else{
    flag2=1;
  }
  int flag3 = -1;
  if((ans[0]=='S'&&s[0]=='o')||(ans[0]=='W'&&s[0]=='x')){
    flag3=0;
  }else{
    flag3=1;
  }
  if(((flag2==0&&ans[N-2]==ans[0])||(flag2==1&&ans[N-2]!=ans[0]))&&((flag3==0&&ans[N-1]==ans[1])||(flag3==1&&ans[N-1]!=ans[1]))){
    flag=1;
    REP(i,N){
      cout << ans[i];
    }
    cout << endl;
    return 0;
  }
  ans=vector<char>(N);
  ans[0]='W';
  ans[1]='S';
  FOR(i,2,N){
    if(ans[i-1]=='S'&&s[i-1]=='o'){
      ans[i]=ans[i-2];
    }else if(ans[i-1]=='S'&&s[i-1]=='x'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else if(ans[i-1]=='W'&&s[i-1]=='o'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else{
      ans[i]=ans[i-2];
    }
  }
  flag2 = -1;
  if((ans[N-1]=='S'&&s[N-1]=='o')||(ans[N-1]=='W'&&s[N-1]=='x')){
    flag2=0;
  }else{
    flag2=1;
  }
  flag3 = -1;
  if((ans[0]=='S'&&s[0]=='o')||(ans[0]=='W'&&s[0]=='x')){
    flag3=0;
  }else{
    flag3=1;
  }
  if(((flag2==0&&ans[N-2]==ans[0])||(flag2==1&&ans[N-2]!=ans[0]))&&((flag3==0&&ans[N-1]==ans[1])||(flag3==1&&ans[N-1]!=ans[1]))){
    flag=1;
    REP(i,N){
      cout << ans[i];
    }
    cout << endl;
    return 0;
  }
  ans=vector<char>(N);
  ans[0]='S';
  ans[1]='W';
  FOR(i,2,N){
    if(ans[i-1]=='S'&&s[i-1]=='o'){
      ans[i]=ans[i-2];
    }else if(ans[i-1]=='S'&&s[i-1]=='x'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else if(ans[i-1]=='W'&&s[i-1]=='o'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else{
      ans[i]=ans[i-2];
    }
  }
  flag2 = -1;
  if((ans[N-1]=='S'&&s[N-1]=='o')||(ans[N-1]=='W'&&s[N-1]=='x')){
    flag2=0;
  }else{
    flag2=1;
  }
  flag3 = -1;
  if((ans[0]=='S'&&s[0]=='o')||(ans[0]=='W'&&s[0]=='x')){
    flag3=0;
  }else{
    flag3=1;
  }
  if(((flag2==0&&ans[N-2]==ans[0])||(flag2==1&&ans[N-2]!=ans[0]))&&((flag3==0&&ans[N-1]==ans[1])||(flag3==1&&ans[N-1]!=ans[1]))){
    flag=1;
    REP(i,N){
      cout << ans[i];
    }
    cout << endl;
    return 0;
  }
  ans=vector<char>(N);
  ans[0]='W';
  ans[1]='W';
  FOR(i,2,N){
    if(ans[i-1]=='S'&&s[i-1]=='o'){
      ans[i]=ans[i-2];
    }else if(ans[i-1]=='S'&&s[i-1]=='x'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else if(ans[i-1]=='W'&&s[i-1]=='o'){
      if(ans[i-2]=='W'){
        ans[i]='S';
      }else{
        ans[i]='W';
      }
    }else{
      ans[i]=ans[i-2];
    }
  }
  flag2 = -1;
  if((ans[N-1]=='S'&&s[N-1]=='o')||(ans[N-1]=='W'&&s[N-1]=='x')){
    flag2=0;
  }else{
    flag2=1;
  }
  flag3 = -1;
  if((ans[0]=='S'&&s[0]=='o')||(ans[0]=='W'&&s[0]=='x')){
    flag3=0;
  }else{
    flag3=1;
  }
  if(((flag2==0&&ans[N-2]==ans[0])||(flag2==1&&ans[N-2]!=ans[0]))&&((flag3==0&&ans[N-1]==ans[1])||(flag3==1&&ans[N-1]!=ans[1]))){
    flag=1;
    REP(i,N){
      cout << ans[i];
    }
    cout << endl;
    return 0;
  }

  cout << -1 << endl;
}