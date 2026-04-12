/**
 *   author: malviyanshiv
 *   created: 13 April 2019  17:32:32
**/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define RREP(i, a, b) for(int i = a-1; i >= b; i--)
#define FORE(a) for(auto ele : a )
#define ALL(a) begin(a), end(a)
#define RPB(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 0x7fffffff
#define LINF 2000000000000000007
#define F first
#define S second
#define TC int t; cin >> t; while(t--)
#define SET(a,b) memset(a,b,sizeof(a))

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

typedef long long ll;
typedef pair< int, int > PII;


void optimizeIO(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}

int main(){
	optimizeIO();

	int n;
	cin >> n;
	vector<int> arr(n);
	REP(i, 0, n)
		cin >> arr[i];
	int mx = arr[0];
	int cnt = 1;
	REP(i, 1, n)
		if( arr[i] >= mx )
			mx = arr[i], cnt++;
	cout << cnt << endl;
	
	return 0;
}