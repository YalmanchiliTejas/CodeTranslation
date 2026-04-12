#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

ll solve(int N, int *A, int s);

int main(void){
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    sort(A, A+N);
    ll ans = 0;
    ll temp = solve(N, A, N/2);
    if(temp > ans) ans = temp;
    if(N % 2 == 0) temp = solve(N, A, N/2 - 1);
    if(temp > ans) ans = temp;
    cout << ans << endl;
    return 0;
}

ll solve(int N, int *A, int s){
    ll ret = 0, acc = 0;
    int l = 0, r = N-1;
    rep(i, N-1){
        if(i == 0) ret += A[s] - A[l];
        else ret += A[r] - A[l];
        if(i == 0) continue;
        else if(i % 2 == 0) r--;
        else l++;
        if(l == s) l++;
        if(r == s) r--;
    }
    l = 0, r = N-1;
    rep(i, N-1){
        if(i == 0) acc += A[r] - A[s];
        else acc += A[r] - A[l];
        if(i == 0) continue;
        else if(i % 2 == 0) l++;
        else r--;
        if(l == s) l++;
        if(r == s) r--;
    }
    return max(acc, ret);
}