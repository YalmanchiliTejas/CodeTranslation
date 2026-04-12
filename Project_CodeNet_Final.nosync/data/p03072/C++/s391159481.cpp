#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin>>N;
    vector<int> Hn(N);
    for (int i=0;i<N;i++){
        cin>>Hn[i];
    }

    // if (N==1) {
    //     cout << 1 << endl;
    //     return;
    // }

    int ans=0;
    for (int i=0;i<N;i++){
        int seeable=true;
        for (int j=0;j<i;j++) {
            // cout << Hn[i] << "<" << Hn[j] << endl;
            if (Hn[i] < Hn[j]) {
                seeable=false;
                break;
            }
        }

        if (seeable) {
            // cout << i << " " << Hn[i] << endl;
            ans++;
        }
    }

    cout << ans << endl;


    return 0;
}