#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B1(N);
    vector<int> B2(N);
    rep(i, N){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int cnt = 0;
    int n = N / 2;
    int l = 0;
    int r = N-1;
    B1[n] = A[r];
    r--;
    cnt++;
    int d = 1;
    while(cnt < N){
        B1[n-d] = A[l];
        l++; cnt++;
        if(cnt == N)break;

        B1[n+d] = A[l];
        l++; cnt++;
        if(cnt == N)break;

        d++;

        B1[n-d] = A[r];
        r--; cnt++;
        if(cnt == N)break;

        B1[n+d] = A[r];
        r--; cnt++;
        if(cnt == N)break;

        d++;

    }

    cnt = 0;
    l = 0;
    r = N-1;
    B2[n] = A[l];
    l++;
    cnt++;
    d = 1;

    while(cnt < N){
        B2[n-d] = A[r];
        r--; cnt++;
        if(cnt == N)break;

        B2[n+d] = A[r];
        r--; cnt++;
        if(cnt == N)break;

        d++;

        B2[n-d] = A[l];
        l++; cnt++;
        if(cnt == N)break;

        B2[n+d] = A[l];
        l++; cnt++;
        if(cnt == N)break;

        d++;

    }

    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 1; i < N; i++){
        ans1 += abs(B1[i] - B1[i-1]);
        ans2 += abs(B2[i] - B2[i-1]);
    }

    cout << max(ans1, ans2) << endl;

    return 0;
}