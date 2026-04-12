#include<bits/stdc++.h>
using namespace std;

#define fi                      first
#define se                      second
#define pb                      push_back
#define endl                    '\n'
#define all(x)                  x.begin(),x.end()
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(x)                   ((int)x.size())

#define FOR(i,a,b)              for(int i = a; i < b; ++i)
#define REV(i,a,b)              for(int i = a; i >= b; --i)
#define FORE(i,a,b)             for(int i = a; i <= b; ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve();

int32_t main()
{
        fast;
        int t = 1;
        // cin >> t;
        for(int i = 1; i <= t; ++i)
                solve();
        cerr << "Time taken: " << ((clock() * 1000) / CLOCKS_PER_SEC) << "ms\n";
}

template <typename A, typename B>
string to_string(pair<A, B> p);
 
string to_string(const string& s) {
        return '"' + s + '"';
}
 
string to_string(const char* s) {
        return to_string((string) s);
}
 
string to_string(bool b) {
        return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
        bool first = true;
        string res = "{";
        for (int i = 0; i < static_cast<int>(v.size()); i++) {
                if (!first) {
                        res += ", ";
                }
                first = false;
                res += to_string(v[i]); 
        }
        res += "}";
        return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
        string res = "";
        for (size_t i = 0; i < N; i++) {
                res += static_cast<char>('0' + v[i]);
        }
        return res;
}
 
template <typename A>
string to_string(A v) {
        bool first = true;
        string res = "{";
        for (const auto &x : v) {
                if (!first) {
                        res += ", ";
                }
                first = false;
                res += to_string(x);
        }
        res += "}";
        return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
        return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
void debug_out() { 
        cerr << endl; 
}
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
        cerr << " " << to_string(H);
        debug_out(T...);
}
 
#ifdef IGM
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif


#define int ll

string s;
int k;
int n;
int dp[105][105][2][10];
int vis[105][105][2][10];
// string cur;
int rec(int i,int nz,int p,int d) {
	if(i > n)
		return 0;
	else if(i == n) {
		if(nz == k) {
			// debug(cur);
			return 1;
		}
		return 0;
	}
	if(vis[i][nz][p][d])
		return dp[i][nz][p][d];
	int &temp = dp[i][nz][p][d];
	temp = 0;
	vis[i][nz][p][d] = 1;
	int r = 9;
	if(p == 0)
		r = min(r,(int)(s[i]-'0'));
	FOR(x,0,r+1) {
		// cur[i] = (char)(x + '0');
		temp += rec(i+1,(nz + (x > 0)) , (p | (x < s[i]-'0')) , x);
	}
	return temp;
}

void solve() {
      cin >> s;
      cin >> k;
      n = SZ(s);
      // cur = s;
      memset(vis,0,sizeof(vis));
      int ans = rec(0,0,0,0);
      cout << ans << endl;
}