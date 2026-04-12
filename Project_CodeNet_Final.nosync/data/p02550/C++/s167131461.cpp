#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
#define int long long
int flag[100010];
signed main(){
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll>a;
    a.push_back(x);
    flag[x] = 1;
    ll res = 0;
    res += x;
    bool fff = 0;
    ll S = -1;
    rep(i,200000){
        ll p = a[i]*a[i]%m;
        if(p==0)fff = 1;
        if(flag[p]!=0){
            S = flag[p];
            break;
        }
        a.push_back(p);
        flag[p] = i+2;
        res += p;
    }
    int mm = a.size();
    if(!fff){
        ll ans = 0;
        vector<ll> b;
        ll sm = 0;
        ll c = 0;
        for(int i=S-1;i<mm;i++){
            b.push_back(a[i]);
            sm += a[i];
            c++;
            // cerr << b.back()<< " ";
        }
        // cerr << endl;
        for(int i=0;i<min(n,S-1);i++){
            ans += a[i];
        }
        n -= min(n,S-1);
        // cerr << S << endl;
        // cerr << n << " "<< ans << endl;
        ans += sm * (n/c);
        // cerr << n/c << " " << n%c << endl;
        rep(i,n%c){
            ans += b[i];
        }
        cout << ans << endl;
    }else{
        ll ans = 0;
        if(n < mm){
            for(int i=0;i<n;i++){
                ans += a[i];
            }
        }else{
            ans = res;
        }
        cout << ans << endl;
    }
    return 0;
}