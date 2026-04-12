#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0;i < N;i++) cin >> H[i];
    int ans = 0;
    for(int i = 0;i < N;i++){
        int value = *max_element(H.begin(),H.begin() + i);
        if(H[i] >= value) ans++;
    }
    cout << ans << endl;
    return 0;
}