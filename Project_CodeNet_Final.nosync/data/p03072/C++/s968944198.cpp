#include "bits/stdc++.h"
using namespace std;

#define int long long
#define MAX_N (200005)
#define debug(x) cout << #x <<":"<< x << endl;
#define debugArray(x) for(auto p:(x)) cerr << p <<" "; cerr << endl;
#define debugIdx(i, x) cerr << #i <<" : "<< i <<" "<< #x <<" : "<< x << endl;
const int MOD = (int)1e9+7;

signed main() {
	int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++){
        cin >> H[i];
    }

    int ans=1;
    for(int i=1; i<N; i++){
        int mx=0;
        for(int j=i-1; j>=0; j--){
            mx = max(mx, H[j]);
        }
        if(H[i] >= mx) ans++;
    }

    cout << ans << endl;

}