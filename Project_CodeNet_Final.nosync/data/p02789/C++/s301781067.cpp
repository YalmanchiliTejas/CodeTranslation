#include <bits/stdc++.h>

#define f(i, a, b, c) for(int i = a ; i < b ; i += c)
#define fr(i, a, b, c) for(int i = a ; i >= b ; i -= c)
#define fit(it, v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define frit(it, v) for(auto it = v.rbegin() ; it != v.rend() ; ++it)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define eb emplace_back
#define pb push_back
#define lli long long int
#define modn 998244353
#define NL '\n'

using namespace std;

typedef vector< int > vi;
typedef vector< char > vc;
typedef vector< bool > vb;
typedef vector< lli > vli;
typedef vector< vector< char > > vvc;
typedef vector< vector< int > > vvi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef pair< lli, int> pli;
typedef pair< lli, lli> pll;
typedef set< int > si;
typedef set< ii > sii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	#ifdef LOCAL_TEST
		clock_t z = clock();
    	ifstream h("in");
	    ofstream g("out");
	#else
	    #define h cin
	    #define g cout
	#endif // LOCAL_TEST
	
	int n, m;
	h >> n >> m;
	g << (n == m ? "Yes" : "No");
	
	#ifdef LOCAL_TEST
		cerr << "Time taken is: " << double(clock() - z) / CLOCKS_PER_SEC << NL;
		h.close();
		g.close();
	#endif // LOCAL_TEST
}

