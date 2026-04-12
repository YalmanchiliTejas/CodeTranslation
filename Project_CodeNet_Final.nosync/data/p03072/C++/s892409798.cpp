#include <bits/stdc++.h>
#define RANGE(i,n) for(int i=0;i<n;i++)
typedef long long ll;

using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> H(N,0);
    int count = 0;
    int max = -1;
    RANGE(i,N){
        cin >> H[i];
        if(H[i] >= max){
            count ++;
            max = H[i];
        }
    }
    cout << count << endl;
}
