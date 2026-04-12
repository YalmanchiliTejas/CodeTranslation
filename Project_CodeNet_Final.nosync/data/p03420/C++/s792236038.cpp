#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll ZERO = 0;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    int N,K;
    cin >> N >> K;
    ll ret = 0;
    for(int i = K + 1;i <= N;i++) {
        int A = K;
        int B = i - 1;
        while(A <= N) {
            if(A == 0) {
                ret += min(B, N);
            }
            else {
                ret += (min(B, N) - A + 1);
            }
            A += i;
            B += i;
        }
    }
    cout << ret << endl;
}