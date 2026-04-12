#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h.at(i);

    int cnt = 0;
    int mh = h.at(0);
    for(int i=0; i<n; i++){
        if(mh<=h.at(i)){
            mh = h.at(i);
            cnt++;
        }
    }

    cout << cnt << endl;
}
