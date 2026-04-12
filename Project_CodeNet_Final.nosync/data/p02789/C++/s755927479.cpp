using namespace std;

#include<bits/stdc++.h>

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define getBit(x,i) (x&(1<<i))
#define setBit(x,i) (x|(1<<i))
#define mem(A,N) memset(A,N,sizeof(A))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define rep(i, x, y)  for(int i = x; i < y; ++i)
#define Rep(i, x, y)  for(int i = x; i <= y; ++i)
#define srep(i, x, y) for(int i = x; i > y; --i)
#define sRep(i, x, y) for(int i = x; i >= y; --i)
#define All(v) v.begin(),v.end()
#define sortA(a) sort(a, a+n)
#define sortArr(a, i, n) sort(a+i, a+n)
#define SortArr(a, i, n) sort(a+i, a+n+1)
#define Sort(x) sort(x.begin(), x.end())
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define fi first
#define se second
#define concatenate(a, b) std::copy(b.begin(), b.end(), std::back_inserter(a));
#define fcout(x) cout << fixed << setprecision(x)
#define ifcout(x, a, b) if(x) cout << a << '\n'; else cout << b << '\n'
// #define concatenate(a, b) a.insert(b.end(), b.begin(), b.end());
// std::move(b.begin(), b.end(), std::back_inserter(a)); "Undefined behaviour if a actually is b (which is OK if you know that can never happen - but worth being aware of in general purpose code)"
#define makeUnique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define inRange(x, a, b) (a <= x && x < b)

#define linf 0x7FFFFFFFFFFFFFFF
#define inf 0x7FFFFFFF
#define mod 1000000007
#define eps 1e-9
#define Pi 3.14159265358979323846

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define write(x) cerr << #x << " = " << (x) << ", ";
#define writeI0 cerr << "i = " << 0 << ", ";
#define dumpI0 cerr << "i = " << 0 << endl;
#define printSet(s) for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cout << *it : cout << ' ' << *it; cout << endl;
#define printMap(m) for(auto it = m.begin(); it!=m.end(); it++) (it==m.begin())? cout << '(' << it->first << ", " << it->second << ')' : cout << " (" << it->first << ", " << it->second << ')'; cout << endl;
#define printPairSet(s) for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cout << '(' << it->first << ", " << it->second << ')' : cout << " (" << it->first << ", " << it->second << ')'; cout << endl;
#define printVector(x) for(auto it = x.begin(); it!=x.end(); it++) (it==x.begin())? cout << *it : cout << ' ' << *it; cout << endl;
#define printArray(a,x,y) for(auto it = a+x; it != a+y; it++) (it==a+x)? cout << *it : cout << ' ' << *it; cout << endl;
#define PrintArray(a,x,y) for(auto it = a+x; it != a+y+1; it++) (it==a+x)? cout << *it : cout << ' ' << *it; cout << endl;

// ***************** End Of Template ********************

ll f(ll y) {
	
	if (y <= 1) return y;
	
	return f(y-1) + f(y-2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	if (n == m)
		cout << "Yes\n";
	else
		cout <<"No\n";
	
	
	return 0;
}