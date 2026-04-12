#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }


int main(){
    int N, M;
    cin >> N >> M;
    cout << ((N == M) ? "Yes" : "No") << endl;
}