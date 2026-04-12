#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N, K;
    cin >> N >> K;
    if(K == 0){
        cout << N * N << endl;
        return 0;
    }

    long long ans = 0;
    for(long long b=K+1; b<=N; b++){
        long long nmx;
        long long tmp = N - b + 1;
        if(tmp % b == 0) nmx = tmp / b;
        else nmx = tmp / b + 1;
        long long tmp2 = nmx*(b-1-K+1) + max(0LL, (N-nmx*b-K+1));
        ans += tmp2;
    }
    cout << ans << endl;
    return 0;
}