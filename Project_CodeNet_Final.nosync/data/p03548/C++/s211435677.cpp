#include <bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<"="<<x
#define nl cout<<"\n"
#define frn(i,n) for(int i = 0;i < n;i++)
#define fr(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define trav(x,c) for(auto &x:c)
using namespace std;

int toint(string s) {
  int ans = 0;
  for(char x: s) ans = ans*10 + (x - '0');
  return ans;
}

int sum(int x) {
  int s = 0;
  while(x) {
    s += x%10;
    x /= 10;
  }
  return s;
} 

int main() {
  int x,y,z;
  cin>>x>>y>>z;
  int ans = (x-z)/(y+z);
  cout<<ans;
}