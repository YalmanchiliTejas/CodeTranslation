#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define  st first
#define  nd second
#define int long long 


template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef cc_hash_table<int, int, hash<int > > ht;

const int  M    = 1000000007;
const int  maxn =  100005 ;
const long long   inf  =  LONG_LONG_MAX    ;
const long double eps = 1.084202e-19;

int modular_pow(int  base, int exponent, int modulus=M)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


int32_t main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL); 
     int n ; 
     cin >> n ; 
     int a[n] ; 
     int ans = 0 ; 
     int k= 0 ;
     for ( int i = 0 ; i < n ; i++){
           cin >> a[i] ; 
           ans = (((ans - ((a[i]*a[i])%M))%M) + M)%M;
           k = (k +a[i])%M;
     }
     k = (k *k)%M;
     ans  = (ans + k)%M;
     ans = (ans * modular_pow(2,M-2))%M;
     cout << ans ;  

}
/*

*/