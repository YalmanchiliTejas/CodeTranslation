#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>H(N);
    for(int i=0; i<N; ++i) {
        cin >> H[i];
    }
    int ans = 1;
    int highest = 0;
    for(int i=1; i<N; ++i) {
        if(H[i] >= H[highest]) {
        ans++;
        highest = i;
        }
    }
    cout << ans;
    return 0;
}