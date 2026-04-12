#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

int f(vi &A, int n) {
    int res = 0;
    int l=A[0], r=A[0];
    n--;
    int tl=1, tr=A.size()-1;
    while(n > 0) {
        //右処理
        if(n-1==0) {
            res += max(abs(l-A[tr]), abs(r-A[tr]));
            break;
        }
        if(abs(l-A[tr])+abs(r-A[tr-1]) > abs(l-A[tr-1])+abs(r-A[tr])) {
            res += abs(l-A[tr])+abs(r-A[tr-1]);
            l = A[tr]; r = A[tr-1];
        } else {
            res += abs(l-A[tr-1])+abs(r-A[tr]);
            l = A[tr-1]; r = A[tr];
        }
        tr -= 2;
        n -= 2;
        if(n==0) break;

        //左処理
        if(n-1==0) {
            res += max(abs(l-A[tl]), abs(r-A[tl]));
            break;
        }
        if(abs(l-A[tl])+abs(r-A[tl+1]) > abs(l-A[tl+1])+abs(r-A[tl])) {
            res += abs(l-A[tl])+abs(r-A[tl+1]);
            l = A[tl]; r = A[tl+1];
        } else {
            res += abs(l-A[tl+1])+abs(r-A[tl]);
            l = A[tl+1]; r = A[tl];
        }
        tl += 2;
        n -= 2;
        if(n==0) break;
    }
    return res;
}

signed main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    int n = N;

    SORT(A);
    int res = f(A, n);
    GSORT(A);
    res = max(res, f(A, n));

    cout << res << endl;

    return 0;
}