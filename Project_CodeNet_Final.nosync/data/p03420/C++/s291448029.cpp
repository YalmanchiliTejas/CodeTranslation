#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define ull long long
using namespace std;

const int nmax = 100100;
ull N, K;

void read(){
    cin >> N >> K;
}
ull max(ull x, ull y)
{
    return x < y ? y : x;
}
void solve(){
    if ( K == 0)
    {
        cout << N * N << endl;
        return;
    }
    ull ans = 0;
    for(ull b = K+1; b<=N; ++b)
    {
        ull x = N/b;
        ull y = N%b;
        ans += x * (b-K); 
        if(y != 0){
           ans += max(0ULL, y - K + 1);
        }

    //cout << b << ' ' << ans << endl;
    }
    cout << ans << endl;
}

int main(){
    read();
    solve();
}