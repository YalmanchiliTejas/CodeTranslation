#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }

    int ans = 1;
    int maxh = H[0];
    for(int i = 1; i < N; i++){
        maxh = max(maxh, H[i]);
        if(maxh == H[i]){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}