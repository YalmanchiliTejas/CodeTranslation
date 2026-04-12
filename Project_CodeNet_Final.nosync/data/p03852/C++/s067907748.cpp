#include <bits/stdc++.h>                                                                     
                                                                                             
using namespace std;                                                                         
                                                                                             
#define all(x) x.begin(), x.end()                                                            
#define rep(i, n) for (int i = 0; i < n; ++i)                                                
#define reps(i, m, n) for (int i = m; i <= n; ++i)                                           
                                                                                             
using i64 = long long;                                                                       
using pii = pair<i64, i64>;                                                                  
                                                                                             
template<class A, class B>inline bool chmax(A &a, const B &b){return b > a ? a = b,1 : 0;}   
template<class A, class B>inline bool chmin(A &a, const B &b){return b < a ? a = b,1 : 0;}   
                                                                                             
constexpr int INF = 0x3f3f3f3f;                                                              
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;                                                   
constexpr int MOD = int(1e9) + 7;                                                            
                                                                                             
signed main()                                                                                
{                                                                                            
  ios::sync_with_stdio(false);                                                               
  cin.tie(nullptr);                                                                          
  char c;                                                                                    
  cin >> c;                                                                                  
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cout << "vowel" << "\n";     
  else cout << "consonant" << "\n";                                                          
  return 0;                                                                                  
}                                                                                            
