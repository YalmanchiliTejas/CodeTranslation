#include <bits/stdtr1c++.h>

using namespace std;
#define INP "solve"
#define OUT "solve"
const int QQ = 3e5 + 10;
const int maxN = 3e5 + 10;
const int maxM = 3e5 + 10;
const int oo = 1e9;
const int module = 1e9 + 7;

void doc() {
    freopen(INP ".inp","r",stdin);
    freopen(OUT ".out","w",stdout);

}

int LIS(vector <int> &a) {
    vector <int> b;
    for (int x : a) {
        auto Pos = lower_bound(b.begin(), b.end(), x + 1);
        if (Pos == b.end()) b.push_back(x);
        else *Pos = x;
    }
    return (int)b.size();
}
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x: a) cin >> x;
    reverse(a.begin(), a.end());
    cout << LIS(a);
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //doc();
    solve();
}
