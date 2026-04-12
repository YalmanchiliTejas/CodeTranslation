#include <bits/stdc++.h>

using namespace std;

/**
 *  Name: Chris M. Perez
 *  University: Interamerican University Metro Campus
 *
**/

#define endl '\n'
#define MOD 10E9
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd(x , y) __gcd(x , y)
#define all(x) (x).begin() , (x).end()
#define forn(i , a , b) for(int i=(a);i<(b);i++)
#define forrange(j , a , b) for(int j=(a);j<=(b);j++)
#define nestedforn(i , a , b , j , c , d) for(int i=(a);i<=(b);i++) for(int j=(c);j<=(d);j++)
#define sort_all(x) sort(all(x))
#define zeros_at_beginning(x) __builtin_clz(x)
#define zeros_at_end(x) __builtin_ctz(x)
#define ones(x) __builtin_popcount(x)
#define parity_even_or_odd_ones __builtin_parity(x)


typedef vector<int> vi;
typedef pair<int , int> pii;
typedef tuple<int , int , int> tiii;
typedef vector<pii> vpii;
typedef vector<tiii> vtiii;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long long int lli;

             
inline int input(){
  int n;
  scanf("%d" , &n);
  return n;
}
                                                                                    
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;  

#ifdef LOCAL_DEFINE
  freopen("input.txt" , "rt" , stdin);
#endif
  
  int n; cin >> n;
  string s; cin >> s;
  int k; cin >> k;
  forn(i , 0 , n) if(s[i] != s[k - 1]) s[i] = '*';
  cout << s << endl;
  
                                                   
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif  
  return 0;
}