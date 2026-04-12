#define REP(i, n) for(int i = 0;i < n;i++)
#define INF 2e9
#define ll long long
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ALL(v) v.begin(), v.end()

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int h1; cin >> h1;
    int r = 1;
    REP(i, n-1) {
        int h; cin >> h;
        if (h >= h1) {
            r++;
            h1 = h;
        }
    }
    cout << r << endl;
}

