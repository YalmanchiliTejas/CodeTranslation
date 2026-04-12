#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;

    int m = -1;
    int ans = 0;

    for (int i = 0;i < N;i++){
        int H; cin >> H;
        if(H >= m){ans++; m = H;}
    }

    cout << ans << endl;

    return 0;

}