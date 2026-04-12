#include <bits/stdc++.h>
 
using namespace std;
 
#define M 			50005
#define Fi			first
#define stop 		return
#define Se 			second
#define S(n) 		cin >> n
#define P(n) 	 	cout << n
#define mp 			make_pair
#define pb 			push_back
#define pp 			pop_back
#define pf 			pop_front
#define start 		int main()
#define sp   		cout << " "
#define nl      	cout << "\n"
#define	mem(n, a)	memset((n), (a), sizeof(n))
#define prec(n)		cout << fixed << setprecision(n)
#define F(i, n, r)  for(int i = (n); i < (r); i ++)
#define PI			3.14159265358979323846264338327951
#define fast 		ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using ll = long long;
using ss = stringstream;
using ul = unsigned long long;
 
typedef set < int > 		st;
typedef vector < ll > 		vl;
typedef vector < int > 		vi;
typedef map < ll, ll > 		ml;
typedef pair <int, int> 	pr;
typedef vector < string > 	vs;
typedef map < string, ll > 	ms;
typedef map < string, int > mi;
typedef vector < pr > 		vp;
 
template < typename T > inline T LCM(T a, T b) 		 { return (a * b) / GCD(a, b); }
template < typename T > inline T GCD(T a, T b) 		 { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > inline T _max(T a, T b, T c) { return max( max( a, b ), c ); }
template < typename T > inline T _min(T a, T b, T c) { return min( min( a, b ), c ); }
 
const int inf 	  =  99999999;
const int neg_inf = -99999999;

start
{
    fast;
    int x, y, z;
    S(x), S(y), S(z);
    x -= z;
    int o = 0;
    int count = 0;
    while(1) {
        if(o + y + z > x) {
            break;
        }
        count ++;
        o += y + z;
    }
    P(count), nl;
    stop 0;
}