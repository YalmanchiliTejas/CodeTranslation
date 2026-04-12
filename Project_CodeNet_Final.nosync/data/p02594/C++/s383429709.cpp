/* AUTHOR : UTKARSH CHAUHAN */

#include<bits/stdc++.h>
using namespace std;
       
#define ff              first
#define ss              second                            
#define int             long long
#define rep(i,j,k)      for(int i=(j); i<(int)k; ++i)
#define rrep(i,k,j)     for(int i=(int)k-1; i>=(j); --i)
#define pb              push_back
#define mp              make_pair
#define pii             pair<int, int>
#define endl            "\n"
#define vi              vector<int>
#define mii             map<int, int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int, vi, greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x, y)        fixed << setprecision(y) << x
#define mk(arr, n, type)type *arr = new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define PI              3.14159265358979323846264338327950L
#define span(a)         begin(a), end(a)
#define parent(i)       (i >> 1)
#define left(i)         (i << 1)
#define right(i)        (left(i) | 1)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
       
       
       
       
void c_p_c() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif  
}      


double pi = 3.141592653589;

// int gcd (int a, int b) {
//   if (b == 0) return a;
//   else return gcd (b, a % b);
// }    
// int gcd(int a, int b, int& x, int& y) {
//   if (b == 0) {
//     x = 1;
//     y = 0;
//     return a;
//   }  
//   int x1, y1;
  
//   int d = gcd(b, a % b, x1, y1);
//   x = y1;
//   y = x1 - y1 * (a / b);
//   return d;
// }   
// int lcm (int a, int b)  {
//   return a / gcd(a, b) * b;
// }   
// int fact (int n){
//   if (n == 0) return 1 ;
//   else return n * fact(n - 1); 
// }   
 
// bool isPrime(int x) {
//   for (int d = 2; d * d <= x; d++) if (x % d == 0) return false;
//   return true;
// }
 
// int divisor(int number)
// {
//         int i;
//         for (i = 2; i <= sqrt(number); i++)
//         {
//                 if (number % i == 0)
//                 {
//                        return number/i;
//                 }
//         }
//         return 1;
// }  
inline void solve() 
{
	int n; cin >> n;
	n >= 30 ? cout << "Yes" : cout << "No";
}    
int32_t main() 
{
      //c_p_c();
      //w(x)
      solve();
      return 0;
} 