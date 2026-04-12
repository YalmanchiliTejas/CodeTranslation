#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++) cin >> H[i];
    int M = 0;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(H[i] >= M) ans++;
        M = max(M, H[i]);
    }
    cout << ans << endl;
}