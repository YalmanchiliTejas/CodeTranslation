#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    int N;
    cin >> N;
    ll a[N];
    REP(i, N) cin >> a[i];
    ll res = 0;
    while(1){
        bool flag = false;
        REP(i, N){
            if(a[i]>=N){
                flag = true;
                res += a[i]/N;
                REP(j, N){
                    if(j!=i){
                        a[j] += (a[i]/N);
                    }
                }
                a[i] = a[i]%N;
            }
        }
        if(!flag) break;
    }
    cout << res << endl;
    return 0;
}