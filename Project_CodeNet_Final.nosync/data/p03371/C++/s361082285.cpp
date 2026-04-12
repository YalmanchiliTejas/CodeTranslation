#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;
    int ret = min(A * X + B * Y,C * max(X,Y));
    if(X > Y) {
        ret = min(ret,Y * C + A * (X - Y));
    }
    else {
        ret = min(ret,X * C + B * (Y - X));
    }
    cout << ret << endl;
}