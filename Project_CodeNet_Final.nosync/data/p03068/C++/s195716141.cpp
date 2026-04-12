#include <bits/stdc++.h>
#define RANGE(i,n) for(int i=0;i<n;i++)
typedef long long ll;

using namespace std;

signed main() {
    int N, K;
    cin >> N;
    vector<char> S(N);
    RANGE(i,N) cin >> S[i];
    cin >> K;

    char target = S[K-1];
    RANGE(i,N){
        if(S[i] == target){}
        else S[i] = '*';
    }

    RANGE(i,N) cout << S[i];
    cout <<  endl;
}
