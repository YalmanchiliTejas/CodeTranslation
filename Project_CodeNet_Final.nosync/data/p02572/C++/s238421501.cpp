#include <bits/stdc++.h>
using namespace std;

#define int           long long 
#define S             second
#define F             first
#define pb            push_back
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend() 
#define lb            lower_bound
#define si(c)         (int)((c).size())
#define lcm(a, b)      (a * (b / __gcd(a,b)))  
#define inf           (int)(1e18)
#define endl          '\n'
#define mp            make_pair
#define time(s)       (double(clock()-s)/double(CLOCKS_PER_SEC))
#define debug(args...)    _F(#args, args)
#define vi            std::vector<int>
#define pii           pair<int, int> 
#define vpi           vector<pii>

clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

template<typename T> void _F(const char *name, T arg1){ cerr << name << " = " << arg1 << endl;}
template<typename T, typename... Args> void _F(const char *names, T arg1, Args... args)
{ const char *name = strchr(names, ',');cerr.write(names, name-names) << " = " << arg1 << endl;_F(name+2, args...);}

template< typename T1, typename T2 > istream& operator>>(istream& in, pair<T1, T2> &q){ in >> q.F >> q.S; return in;}
template< typename T1, typename T2 > ostream& operator<<(ostream& out, pair<T1, T2> &q){ out << q.F << " " << q.S; return out;}
template< typename T1, typename T2 > pair<T1, T2> operator+(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F+p2.F, p1.S+p2.S};}
template< typename T1, typename T2 > pair<T1, T2> operator-(pair<T1, T2> p1, pair<T1, T2> p2){ return {p1.F-p2.F, p1.S-p2.S};}
template< typename T1, typename T2 > bool operator<(pair<T1, T2> p1, pair<T1, T2> p2){ return p1 < p2 ;}

template<typename T> void Unique(vector<T> &v){
    sort(all(v)), v.resize(distance(v.begin(), unique(all(v))));
}

const int M = 1e9+7;

void solve(int &test) {
	int n, ans = 0;

	cin >> n;

	int cur = 0, x;
	for(int i = 0; i < n; i++) {
		cin >> x;

		ans += cur*x;
		ans%= M;

		cur += x;
		cur %= M;
	}

	cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);   
    start = clock();
    
  
    int test = 1;
    // cin >> test;

    cout << fixed << setprecision(2);
     
    for(int i = 1; i <= test; ++i){
        solve(i); 
    }

    cerr << time(start);
    return 0;
}