#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i,N) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    B = A;
    deque<ll> Q;
    int i = 0, j = N-1;
    Q.push_front(A[i++]);
    while (i<=j) {
        if (i <= j) Q.push_front(A[j--]);
        if (i <= j) Q.push_back(A[j--]);
        if (i <= j) Q.push_front(A[i++]);
        if (i <= j) Q.push_back(A[i++]);
    }
    rep(i,N) {A[i] = Q.front(); Q.pop_front();}
    Q.clear();
    i = 0; j = N-1;
    Q.push_front(B[j--]);
    while (i<=j) {
        if (i <= j) Q.push_front(B[i++]);
        if (i <= j) Q.push_back(B[i++]);
        if (i <= j) Q.push_front(B[j--]);
        if (i <= j) Q.push_back(B[j--]);
    }
    rep(i,N) {B[i] = Q.front(); Q.pop_front();}
    ll sum = 0, su2 = 0;
    rep(i,N-1) {
        sum += abs(A[i+1] - A[i]); 
    }
    rep(i,N-1) {
        su2 += abs(B[i+1] - B[i]);
    }
    cout << max(sum,su2) << endl;
}
