#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(auto (i)=a;i<b;i++)
#define list(i, N) for(auto (i)=0;i<N;i++)

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll, ll> pi;
#define mp make_pair
#define pb push_back
#define eb emplace_back

#define int ll
#define INF 1e18+5
#define mod 1000000007

template<class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w; cin >> h >> w;
    vector<string> a(h);
    list(i,h) cin >> a[i];
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    list(i,h){
        list(j,w){
            if(a[i][j]=='#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    list(i,h){
        if(row[i]){
            list(j,w){
                if(col[j]) cout << a[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}