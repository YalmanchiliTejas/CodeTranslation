#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int i=(first);i<(last);++i){cout<<#a<<"["<<i<<"] = "<<(a)[i]<<endl;}
#define PRINTP(p)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#p<<" = ("<<(p.first)<<", "<<(p.second)<<")"<<endl;
#define PRINTI(a,i)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<#i<<"] = "<<#a<<"["<<(i)<<"] = "<<(a)[i]<<endl;
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#define PRINTP(p)
#define PRINTI(a,i)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

ll simulate(vector<ll> &a) {
    int N = a.size();
    ll result = 0;
    while (true) {
        sort(all(a));
        if (a[N - 1] < N) {
            break;
        }
        REP(i, N - 1) {
            ++a[i];
        }
        a[N - 1] -= N;
        ++result;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];

    ll result = 0;
    bool flag = false;
    REP(i, N) {
        if (a[i] >= N - 1 + N * N) {
            a[i] -= N * N;
            REP(j, N) {
                if (j != i) {
                    a[j] += N;
                }
            }
            result += N;
            flag = true;
            break;
        }
    }
    if (flag) {
        REP(i, N) {
            if (a[i] < N + 1) {
                continue;
            }
            ll k = a[i] / (N + 1);
            ll ops = (k - 1) * (N + 1);
            a[i] -= ops;
            result += ops;
        }
    }
    result += simulate(a);
    cout << result << endl;
    return 0;
}