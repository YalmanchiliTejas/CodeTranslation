#include<algorithm>//sort(all(変数),greater<型名>())　で降順に
#include<cmath>//切り上げceil(値)
#include<deque>
#include<iomanip>//setprecision(数字)
#include<iostream>
#include<list>
#include<map>
#include<numeric> //xとyの最大公約数は__gcd(x,y),xとyの最小公倍数は(x*y)/__gcd
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>

#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<tuple>
#include<utility>
#define rep(i,n) for(ll i=0; i<n; i++)
#define vll vector<ll>
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int n;  cin >> n;
  vi h(n);
  rep(i,n){
    cin >> h[i];
  }
  int ans = 0;
  rep(i,n){
    bool flag = true;
    rep(j,i){
      if(h[i] < h[j]){
        flag = false;
        break;
      }
    }
    if(flag){
      ans++;
    }
  }
  cout << ans;
  return 0;
}
