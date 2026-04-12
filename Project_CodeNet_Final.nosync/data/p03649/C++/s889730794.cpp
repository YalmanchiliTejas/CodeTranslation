#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define SORTR(v,n) sort(v, v+n, greater<int>());
#define SORTPairSecond(v, n) sort(v, v+n, pairCompareSecond);
#define int long long    // %d=>%lld, 1<<n  => 1LL<<n
#define pb push_back

using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> piii;
typedef pair<ll, pll> plll;
bool pairCompareSecond(const pii& firstEl, const pii& secondEl) {
    return firstEl.second > secondEl.second;
}

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
// const ll LLINF = 1LL << 50;
const double PI = acos(-1);
const double EPS = 0.000000001;


const int MAX_n = 50;
int n,a[MAX_n],b[MAX_n];

bool solve(int mid){
    for(int i = 0;i < n;i++){
        b[i]=a[i];
    }

    int need=0;

    while(1){
        int maxindx = max_element(b,b+n) - b ;

        if(b[maxindx]>=n){
            need+=b[maxindx]/n;
            for(int j = 0;j < n;j++){
                if(maxindx!=j)
                    b[j]+=b[maxindx]/n;
            }
            b[maxindx]-=b[maxindx]/n *n;
        }


        bool f=1;
        for(int i = 0;i < n;i++){
            if(b[i]>=n){
                f=0;
                break;
            }
        }
        if(f){
            break;
        }
    }



    if(need<=mid)
        return 1;
    else {
        return 0;
    }

}

signed main(){

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int ok=LLINF;   // 解が存在する値
    int ng=-1;    // 解が存在しない値

    while (abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        if(solve(mid)){
            ok=mid;
        }else{
            ng = mid;
        }
    }

    cout<< ok<< endl;


    return 0;
}