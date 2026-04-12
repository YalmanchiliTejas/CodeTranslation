#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define reppe(i,a,b) for(int i = (int)(a) ; i <= (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repme(i,a,b) for(int i = (int)(a) ; i >= (int)(b) ; --i)

typedef long long ll;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

/*
LV1   BPPPB
LV2  BBPPPBPBPPPBB
LV3 BBBPPPBPBPPPBBPBBPPPBPBPPPBBB
*/
long long count(int N) {
    if (N == 1) return 5;
    else return 3 + 2 * count(N-1);
}
long long countP(int N) {
    if (N == 1) return 3;
    else return 1 + 2 * countP(N-1);
}

long long res = 0;
void solve(int N, long long X){
    if (N == 1) {
        if (X == 2) res += 1;
        if (X == 3) res += 2;
        if (X >= 4) res += 3;
        return;
    }
    
    if (X == 1) return;
    if (X <= count(N) / 2){
        solve(N-1, X-1);
    } else if (X == count(N) / 2 + 1){
        res += countP(N-1) + 1;
    } else if (X > count(N) / 2 + 1 && X < count(N)){
        res += countP(N-1) + 1;
        solve(N-1, X - count(N-1) - 2);
    } else res += countP(N);
};
int main() {
    int N; cin >> N;
    long long X; cin >> X;
    solve(N,X);
    cout << res << endl;
}
