#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef vector<LL> 		VL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) cin>>n
#define dout(n) cout<<n<<"\n"
//# define M_PI           3.14159265358979323846264338327950288

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// set_name.find_by_order(k) It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time
// set_name.order_of_key(k) It returns to the number of items that are strictly smaller than our item k in O(logn) time.
LL n,x;
VL arr;
VL prr;
LL rec(LL n, LL x){
	if(x == 1)
		return (n == 0) ? 1 : 0;
	if(x > 1 && x <= 1 + arr[n-1])
		return rec(n-1, x-1);
	if(x == 2 + arr[n-1])
		return 1 + prr[n-1];
	if(x > 2 + arr[n-1] && x <= 2 + 2*arr[n-1])
		return 1 + prr[n-1] + rec(n-1, x - 2 - arr[n-1]);
	if(x == 3 + arr[n-1])
		return prr[n];
}
int main() {
	#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
	srand(chrono::steady_clock::now().time_since_epoch().count());
	off;
	cin>>n>>x;
	arr.resize(n+1);
	prr.resize(n+1);
	// length of burger of level i
	arr[0] = 1;
	// number of P in burger of level i
	prr[0] = 1;
	rep(i,1,n+1){
		arr[i] = 2*arr[i-1] + 3;
		prr[i] = 2*prr[i-1] + 1;
	}
	cout<<rec(n, x);
  	return 0;
}