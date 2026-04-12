#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long i = 0; i < n; i++)
#define erep(i, n) for(long i = 1; i <= n; i++)
const long MOD = 1000000007;
#define all(a) a.begin(), a.end()
#define eall(a) a.begin()+1, a.end()
#define show(ans)  cout << ans << endl;

long N, X;

long a(long n){
    long tmp = 1;
    rep(i, n+2) tmp *= 2;
    return tmp - 3; 
}
long b(long n){
    long tmp = 1;
    rep(i, n+1) tmp *= 2;
    return tmp - 1;
}

long DP(long x, long n){
    if(x == 1 && n == 0) return 1;
    else if(x == 0) return 0;
    else if(x == a(n)){
        x--;
        if(x <= 1 + a(n-1)) return DP(x - 1, n - 1);
        else return b(n - 1) + 1 + DP(x - (2 + a(n - 1)), n - 1);
    }
    else{
        if(x <= 1 + a(n-1)) return DP(x - 1, n - 1);
        else return b(n - 1) + 1 + DP(x - (2 + a(n - 1)), n - 1);
    }
}

int main(){
cin >> N >> X;
show(DP(X, N));









return 0;
}