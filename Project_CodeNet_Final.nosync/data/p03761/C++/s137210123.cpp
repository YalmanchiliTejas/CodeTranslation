#include <bits/stdc++.h>
using namespace std;
#define dbg(x) #x "=" << x << " "
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int n;
    string s;
    cin >> n;
    map<char, int> cnt[n];
    fore(i,0,n) {
        cin >> s;
        fore(j,0,s.size()) {
            cnt[i][s[j]]++;
        }
    }
    fore(c,'a','z'+1) {
        int mn = 100;
        fore(i,0,n) {
            mn = min(mn, cnt[i][c]);
        }
        cout << string(mn, c);
    }
    cout << endl;
}
