#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N, X, M;
ll A[300000];

ll Last;
ll Start;
map<ll, ll> mp;
int main() {
    cin >> N >> X >> M;
    A[0] = X;
    mp[X] = 0;
    for(int i = 1; ; i++) {
        A[i] = (A[i-1] * A[i-1]) % M;
        if(mp.count(A[i])) {
            Last = i;
            Start = mp[A[i]];
            break;
        }
        mp[A[i]] = i;
    }
    /*
    for(int i = 0; i <= Last; i++) {
        cerr << i << " " << A[i] << endl;
    }
    */
    ll ans = 0;
    if(N <= Last) {
        for(int i = 0; i < N; i++) ans += A[i];
    } else {
        for(int i = 0; i < Start; i++) ans += A[i];
        ll sum = 0;
        for(int i = Start; i < Last; i++) sum += A[i];
        ans += sum * ((N - Start) / (Last - Start));
        ll rest = N - Start - (Last - Start) * ((N - (Start)) / (Last - Start));
        //cerr << Start << " "<< Last << " " << sum << " " << rest << endl;
        for(int i = 0; i < rest; i++) ans += A[Start+i];
    }
    cout << ans << endl;
    return 0;
}
