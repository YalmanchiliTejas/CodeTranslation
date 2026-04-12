#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int K,A,B;
    cin >> K >> A >> B;
    if(A <= B && A < K) {
        cout << -1 << endl;
    }
    else if(A <= B) {
        cout << 1 << endl;
    }
    else {
        if(A >= K) {
            cout << 1 << endl;
        }
        else {
            K-=A;
            cout << 1+2*((K+A-B-1)/(A-B)) << endl;
        }
    }
}
