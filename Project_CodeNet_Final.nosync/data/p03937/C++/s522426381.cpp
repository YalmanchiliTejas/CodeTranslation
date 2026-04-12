#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007;
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
const long long INF = 1LL<<60;
int gcd(int a,int b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}
int main() {
    int h,w,cnt = 0;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(a[i][j] == '#') cnt++;
        }
    }
    if(cnt == h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}