/**
 *   Praveen Fulera    
**/

// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl '\n'
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define point pair <double, double>

const int mod = 1e9 + 7;
//const int mod = 998244353;

int power(int n, int k){
  int res = 1;
  for(int i = 1; i <= k; i++){
    res*=n;
  }
  return res;
}

int C(int n, int k){
  if(k < 0)return 0;
  if(k > n) return 0;
  if(k == 0) return 1;
  if(k == 1)return n;
  if(k == 2) return((n*(n-1))/2);
  return (n*(n-1)*(n-2))/6;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif

  string s; cin >> s;
  int k, ans = 0; cin >> k;
  int n = s.size();
  for(char c = '1'; c <= '9'; c++){
         if(s[0] < c) break;
         if(s[0] > c) {ans += (C(n-1,k-1)*power(9,k-1)); continue;}
         ans += (C(n-1,k)*power(9,k));
         if(k == 1) {ans++; break;}
         for(int i = 1; i < n; i++){
           if(s[i] == '0') continue;
           else{
             ans += ((s[i]-'0'-1)*(C(n-i-1,k-2))*power(9,k-2));
             ans += (C(n-i-1,k-1)*power(9,k-1));
             if(k == 2){ans++; break;}
             for(int j = i+1; j < n; j++){
               if(s[j] == '0') continue;
               else{
                  ans += (s[j]-'0'-1)*(C(n-j-1,k-3))*power(9,k-3);
                  ans += (C(n-j-1,k-2)*power(9,k-2));
                  ans++;
                  break;
               }
             }
             break;
           }
         }
  }
  cout << ans << '\n';
}
