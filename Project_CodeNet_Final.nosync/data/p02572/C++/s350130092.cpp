#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define mod (int)(1e9 + 7)
#define PI 3.14159265358979323846264338327950L
// ------------------ Debugging ------------------
#define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout << endl; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << "[ " << *it << " = " << a << " ] ";
    err(++it, args...);
}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}
template <typename T> ostream& operator<<(ostream& os, const vector<T> &p){os << "[ "; for (T x: p) os << x << " "; os << "]" << endl; return os;}
template <typename T> ostream& operator<<(ostream& os, const set<T> &p){os << "{ "; for (T x: p) os << x << " "; os << "}" << endl; return os;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const map<Tk, Tv> &p){os << "{ "; for (pair<Tk, Tv> x: p) os << x << " "; os << "}" << endl; return os;}
// -----------------------------------------------

signed main(){

    fastIO

    int t = 1;
    // cin >> t;
    while (t--){
   		int n;
   		cin >> n;
   		vector<int> a(n), pre(n, 0);
   		for (int i = 0; i < n; i++) {
   			cin >> a[i];
   			pre[i] = a[i];
   		}
   		for (int i = n-2; i >= 0; i--) {
   			pre[i] += pre[i+1];
   			pre[i] %= mod;
   		}

   		int ans = 0;
   		for (int i = 0; i < n-1; i++) {
   			int val = a[i] * pre[i+1];
   			val %= mod;

   			ans += val;
   			ans %= mod;
   		}
   		cout << ans << endl;
    }	
    
    return 0;
}