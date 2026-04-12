#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

int uf[100100];
int find(int x){
    return (uf[x] == x) ? x : uf[x] = find(uf[x]);
}

bool merge(int x, int y){
    int p1 = find(x), p2 = find(y);
    if (p1 == p2) return false;
    uf[p2] = p1;
    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<piii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].X.X >> arr[i].X.Y;
        arr[i].Y = i;
    }
    vector<piii> xs(arr), ys(arr);
    sort(xs.begin(), xs.end(), [](const piii &p1, const piii &p2){
            return p1.X.X < p2.X.X;
        });
    sort(ys.begin(), ys.end(), [](const piii &p1, const piii &p2){
            return p1.X.Y < p2.X.Y;
        });
    vector<piii> edges;
    for (int i = 0; i < n-1; i++){
        int dx = xs[i+1].X.X - xs[i].X.X;
        int dy = ys[i+1].X.Y - ys[i].X.Y;
        edges.push_back({{xs[i].Y, xs[i+1].Y}, dx});
        edges.push_back({{ys[i].Y, ys[i+1].Y}, dy});
    }
    sort(edges.begin(), edges.end(), [](const piii &p1, const piii &p2){
            return p1.Y < p2.Y;
        });

    iota(uf, uf+n, 0);

    ll res = 0;
    for (auto &e : edges){
        if (merge(e.X.X, e.X.Y)) res += e.Y;
    }
    cout << res << endl;

}
