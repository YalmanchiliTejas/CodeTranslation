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
    int n;
    cin >> n;
    ll a[n];
    REP(i, n) cin >> a[i];
    deque<ll> dq;
    REP(i, n){
        if(i%2==0){
            dq.push_back(a[i]);
        }else{
            dq.push_front(a[i]);
        }
    }
    if(n%2==1){
        REP(i, n){
            cout << dq[n-1-i] << " ";
        }
    }else{
        REP(i, n){
            cout << dq[i] << " ";
        }
    }
    cout << endl;
    return 0;
}