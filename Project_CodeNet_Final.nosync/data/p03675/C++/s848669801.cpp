#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;
const int INF = 1e15;
const int mod = 1e9 + 7;


signed main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    for(int i = 0; i < n; i++){
        int now = n - 1 - i;
        int tmp = i / 2;
        if(i % 2){
            b[n - 1 - tmp] = a[now];
        }else{
            b[tmp] = a[now];
        }
    }
    rep(i, 0, n){
        cout << b[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl;
}