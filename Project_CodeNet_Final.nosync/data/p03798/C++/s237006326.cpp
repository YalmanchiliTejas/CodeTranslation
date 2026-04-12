#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll mod=(1e+9)+7;
const ll inf=1e+16; 

#define rep(i,m,n) for(ll i=m;i<n;i++)
#define repr(i,m,n) for(ll i=m;i>=n;i--)

bool check(string &res, string &s, char zero, char one){
  ll n=s.size();
  rep(i,0,n) res[i]='?';
  res[0]=zero;
  res[1]=one;
  
  if(!((s[0]=='o')^(res[0]=='S'))) res[res.size()-1]=one;
  else res[res.size()-1]=(res[1]=='S'?'W':'S');
 
  rep(i,2,n-1){
   if(!((s[i-1]=='o')^(res[i-1]=='S'))) res[i]=res[i-2];
   else res[i]= (res[i-2]=='S'?'W':'S');
  }
  
  char flag;
  
  if(!((s[n-2]=='o')^(res[n-2]=='S'))) flag=res[n-3];
  else flag = (res[n-3]=='S'?'W':'S');

  return (res[n-1]==flag)&&((res[n-1]=='S')^(s[n-1]=='o')^(res[n-2]==res[0]));

}

int main(){
   cin.tie(nullptr);
  ios::sync_with_stdio(false);

 ll n;
 string s;
  cin >> n >> s;
 string res=s;
 
 if(check(res,s,'S','S')) {
   cout << res << endl;
   return 0;
 }
 if(check(res,s,'S','W')) {
   cout << res << endl;
   return 0;
 }
 if(check(res,s,'W','W')) {
   cout << res << endl;
   return 0;
 }
 if(check(res,s,'W','S')) {
   cout << res << endl;
   return 0;
 }
  cout << -1 << endl;
 
  
}
