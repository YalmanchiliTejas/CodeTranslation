#include <bits/stdc++.h>

#define f(i, a, b, c) for(int i = a ; i < b ; i += c)
#define fr(i, a, b, c) for(int i = a ; i >= b ; i -= c)
#define fit(it, v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define frit(it, v) for(auto it = v.rbegin() ; it != v.rend() ; ++it)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define NL '\n'
#define modn 1000000007
#define EPS 1e-9

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< lli > vli;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< char > vc;
typedef vector< string > vs;
typedef vector< bool > vb;
typedef set< int > si;
typedef set< ii > sii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifdef LOCAL_TEST
		ifstream h("in");
		ofstream g("out");
		clock_t z = clock();
	#else
		#define h cin
		#define g cout
	#endif//LOCAL_TEST

	int n;
	h >> n;
	vli v(n);
	f(i, 0, n, 1)
		h >> v[i];
	vli temp(n);
	temp[n - 1] = v[n - 1];
	fr(i, n - 2, 0, 1)
		temp[i] = (temp[i + 1] + v[i]) % modn;
	lli ans = 0;
	f(i, 1, n, 1)
		ans = (ans + ((v[i - 1] * temp[i]) % modn)) % modn;
	g << ans;

	#ifdef LOCAL_TEST
		cerr << "Time taken is: " << double(clock() - z) / CLOCKS_PER_SEC << NL;
		h.close();
		g.close();
	#endif//LOCAL_TEST
}
