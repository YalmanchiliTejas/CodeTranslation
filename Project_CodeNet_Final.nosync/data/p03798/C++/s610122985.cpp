#include<bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 32);
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;
template <class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;

#define Endl endl

/*--------------------template--------------------*/

bool check(string s,string t) {
    char S = 'S';
    char W = 'W';
    if(t[0] == t.back()){
        if (t[0] == S) {
            if (s[0] == 'o') {
                if (t[1] == S) {
                    if (t[s.size() - 1] == S) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (t[s.size() - 1] == W) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                if (t[1] == S) {
                    if (t[s.size() - 1] == W) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (t[s.size() - 1] == S) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            if (s[0] == 'o') {
                if (t[1] == S) {
                    if (t[s.size() - 1] == W) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (t[s.size() - 1] == S) {
                        return true;
                    } else {
                        return false;
                    }
                }
            } else {
                if (t[1] == S) {
                    if (t[s.size() - 1] == S) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (t[s.size() - 1] == W) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    } else {
        return false;
    }
}

bool make(string s, string & t) {
    char S = 'S';
    char W = 'W';
    FOR(i, 1, n) {
        if (t[i] == S) {
            if (s[i] == 'o') {
                if (t[i - 1] == S) {
                    t += S;
                } else {
                    t += W;
                }
            } else {
                if (t[i - 1] == S) {
                    t += W;
                } else {
                    t += S;
                }
            }
        } else {
            if (s[i] == 'o') {
                if (t[i - 1] == S) {
                    t += W;
                } else {
                    t += S;
                }
            } else {
                if (t[i - 1] == S) {
                    t += S;
                } else {
                    t += W;
                }
            }
        }
    }

    if (check(s, t)) {
        cout << t.substr(0,s.size()) << endl;
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n >> s;
    
    string t;
    t = "SS";
    if (make(s, t))return 0;
    t = "SW";
    if (make(s, t))return 0;
    t = "WS";
    if (make(s, t))return 0;
    t = "WW";
    if (make(s, t))return 0;
    cout << -1 << endl;
}