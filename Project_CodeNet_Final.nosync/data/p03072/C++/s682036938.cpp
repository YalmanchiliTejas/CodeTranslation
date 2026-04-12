#include <bits/stdc++.h>
using namespace std;

int main(){
int N; cin >> N;
vector<int> H(N);
for (int i = 0; i < N; i++) {
    cin >> H[i];
}

int h_max = 0;
int ans = 0;
for (int i = 0; i < N; i++) {
    if (H[i] - h_max >= 0) {
        h_max = H[i];
        ans++;
    }
}
cout << ans << endl;
}