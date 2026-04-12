#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define D(a) cerr << #a << " = " << a << endl
#else 
    #define D(a) 8 
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define all(a) (a).begin(),(a).end()
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

int main() {
	fastio;
	
    int n; cin >> n;
    map<string, int> m;
    vi c(26, 50);
    forn(_, n) {
        string s; cin >> s;
        vi a(26);
        for (char x : s)
            a[int(x-'a')]++; 
        forn(i, 26) 
            c[i] = min(c[i], a[i]);
    }
    string ans;
    forn(i, 26) forn(j, c[i]) ans += char('a'+i);
    cout << ans << endl;
	return 0;
}
