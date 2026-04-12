#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <stack>
#include <map>
#include <unordered_map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

void printv(VI a) {
    REP(i,a.size()-1) {
        if (a[i] == 0) cout << "S";
        else cout << "W";
    }
    if (a.back() == 0) cout << "S" << endl;
    else cout << "W" << endl;
    exit(0);
}

int main() {
    int n;
    cin >> n;
    VI v(n,-1);
    string s;
    cin >> s;
    
    v[0] = 0;
    if (s[0] == 'o') {
        REPI(i,1,n) v[i] = -1;
        v[1] = 0;
        v[n-1] = 0;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
        REPI(i,1,n) v[i] = -1;
        v[1] = 1;
        v[n-1] = 1;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
    } else {
        REPI(i,1,n) v[i] = -1;
        v[1] = 0;
        v[n-1] = 1;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
        REPI(i,1,n) v[i] = -1;
        v[1] = 1;
        v[n-1] = 0;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
    }
    
    v[0] = 1;
    if (s[0] == 'o') {
        REPI(i,1,n) v[i] = -1;
        v[1] = 1;
        v[n-1] = 0;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
        REPI(i,1,n) v[i] = -1;
        v[1] = 0;
        v[n-1] = 1;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
    } else {
        REPI(i,1,n) v[i] = -1;
        v[1] = 1;
        v[n-1] = 1;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
        REPI(i,1,n) v[i] = -1;
        v[1] = 0;
        v[n-1] = 0;
        REPI(i,1,n-1) {
            if ((s[i] == 'o' && v[i] == 0) || (s[i] == 'x' && v[i] == 1)) {
                int a = v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            } else {
                int a = 1 - v[i-1];
                if (v[i+1] != -1) {
                    if (v[i+1] == a && ((v[n-1] == 0 && s[n-1] == 'o' && v[0] == v[n-2]) || (v[n-1] == 1 && s[n-1] == 'x' && v[0] == v[n-2]) || (v[n-1] == 0 && s[n-1] == 'x' && v[0] != v[n-2]) || (v[n-1] == 1 && s[n-1] == 'o' && v[0] != v[n-2])))
                        printv(v);
                }
                v[i+1] = a;
            }
        }
    }
    cout << -1 << endl;
}

