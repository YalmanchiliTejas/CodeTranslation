#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
const double PI = 3.141592653589793238462643383279;
const int DY[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int DX[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
template<typename T, typename U> inline bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> inline bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
struct Init {
    Init() {
        cout << fixed << setprecision(20);
    };
} init;

int N;
int H[110000];
signed main() {
    int m=0;
    cin>>N;
    for(int i=0;i<N;i++)cin>>H[i];
    int ans=0;
    for(int i=0;i<N;i++)if(H[i]>=m)m=H[i],ans++;
    cout<<ans<<endl;
}
