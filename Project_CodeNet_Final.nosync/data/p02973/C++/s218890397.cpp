#include<bits/stdc++.h>
using namespace std;
void Main(){
    int N, ans = 0, it;
    cin >> N;
    vector<int> A(N), B(N, -1);
    for (auto& a:A) cin >> a;
    for (int i = 0; i<N; i++) {
        it = lower_bound(B.begin(), B.end(), A[i])-B.begin();
        B[it-1] = A[i];
    }
    for (auto b:B) if (b != -1) ans++;
    printf("%d\n", ans);
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}