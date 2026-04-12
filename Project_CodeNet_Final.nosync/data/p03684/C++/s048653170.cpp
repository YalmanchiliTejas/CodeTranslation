#include <iostream>
#include <vector>
#include <algorithm>
 
#define rep(i, n) for(int i = 0; i < (n); ++i)
 
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int n;
int x[100000];
int y[100000];
int p[100000];
PP e[200000 - 2];

int find(int a){
    return p[a] == a ? a : p[a] = find(p[a]);
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    int x = find(a);
    int y = find(b);
    p[x] = y;
}

void make(int* x, PP* e){
    vector<P> v;
    rep(i, n){
        v.push_back(P(x[i], i));
    }
    sort(v.begin(), v.end());
    rep(i, n - 1){
        e[i] = PP(v[i + 1].first - v[i].first, P(v[i].second, v[i + 1].second));
    }
}

int main(){
    cin >> n;
    rep(i, n){
        cin >> x[i] >> y[i];
    }

    make(x, e);
    make(y, e + n - 1);

    rep(i, n){
        p[i] = i;
    }
    sort(e, e + 2 * n - 2);
    int ans = 0;
    rep(i, 2 * n - 2){
        if(!same(e[i].second.first, e[i].second.second)){
            unite(e[i].second.first, e[i].second.second);
            ans += e[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}