#include <bits/stdc++.h>
using namespace std;

long long  Len[51], Pat[51];

long long rec(long long k, long long x){
    if(x == Len[k]) return Pat[k];
    --x;
    long long ans = 0;
    if(x > 0) {
        long long l = min(x, Len[k - 1]);
        ans += rec(k - 1, l);
        x -= l;
    }
    if(x > 0){
        ans++;
        x--;
    }
    if(x > 0){
        long long l = min(x, Len[k - 1]);
        ans += rec(k - 1, l);
    }
    return ans;
}

int main(){
    long long  N, X;
    cin >> N >> X;

    Len[0] = Pat[0] = 1;
    for(int i = 1; i <= N; i++){
        Len[i] = Len[i - 1] * 2 + 3;
        Pat[i] = Pat[i - 1] * 2 + 1;
    }
    cout << rec(N, X) << endl;
    return 0;
}
