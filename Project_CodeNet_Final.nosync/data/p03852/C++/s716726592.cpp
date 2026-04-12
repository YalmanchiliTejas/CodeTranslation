#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

ll gcd(ll x,ll y){
  if(x>y)swap(x,y);
  if(y%x==0)return x;
  return gcd(y-x*(y/x),x);
}

int main(){
  char c;
  cin >> c;
  if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')cout << "vowel";
  else cout << "consonant";
  cout << endl;
}