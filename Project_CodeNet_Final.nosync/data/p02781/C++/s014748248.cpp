#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
#define v(T) vector<T>
#define vv(T) vector<v(T)>
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
template<class T>bool chmax(T &a, const T &b){
    if (a < b) {a = b; return true;}
    return false;
}
template<class T>bool chmin(T &a, const T &b){
    if (a > b) {a = b; return true;}
    return false;
}

int comb(int n, int k){
    if (n<k or k < 0) return 0;
    int ret = 1;
    for (int i = n; i> n-k; i--){
        ret *= i;
    }
    for (int i = 1;i<k+1;i++){
        ret /= i;
    }
    return ret;
}


int main()
{
    string N;
    cin >> N;
    int k;
    cin >> k;
    int m = N.size(), idx = 0;
    vi a(k,1000), b(k, 1000);
    rep(i, m){
        if (N[i] != '0') {
            a[idx] = stoi(N.substr(i, 1));
            b[idx] = i+1;
            idx++;
        }
        if (idx == k) break;
    }
    int ans = 0;
    rep(i, k){
        ans *= 9;
        ans += 9*comb(m-b[i], k-i);
        ans += (a[i]-1)*comb(m-b[i], k-i-1);
    }
    if (idx == k)ans++;
    cout << ans << endl;

    
}

