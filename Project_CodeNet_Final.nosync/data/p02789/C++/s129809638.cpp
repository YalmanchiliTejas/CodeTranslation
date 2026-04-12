#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

// cout<<fixed<<setprecision(10);

template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

const int N_MAX = 1e5;
string str[N_MAX];

ll kaijou(int k){
    if(k == 1) return 1;
    return k* kaijou(k-1);
}

int main(){
    int n, m; cin >> n >> m;
    if(n == m){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" <<endl;
    }
}

