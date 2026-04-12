#include <bits/stdc++.h>
using namespace std;

template<typename ...> static inline int gc(void) { return getchar(); }
static inline void read(long long int &x){int k,m=0;x=0;for(;;){k=gc();if(k==45){m=1;break;}if(48<=k&&k<=57){x=k-48;break;}}for(;;){k=gc();if(k<48||k>57)break;x=x*10+k-48;}if(m)x=-x;}
static inline void uread(long long int &x){int k;x=0;for(;;){k=gc();if(48<=k&&k<=57){x=k-48;break;}}for(;;){k=gc();if(k<48||k>57)break;x=x*10+k-48;}}

long long int par[114514], rnk[114514];
long long int N, a, b;
pair<long long, long long> x[114514], y[114514], c[114514];
vector<pair<long long, pair<long long, long long>>> v;

void uf(long long int n){
    iota(par, par + n, 0);
}

long long int fnd(long long int i){
    if(par[i] == i)return i;
    return par[i] = fnd(par[i]);
}

void unon(long long int x, long long int y){
    x = fnd(x);
    y = fnd(y);
    if(!(x ^ y)) return;
    if(rnk[x] < rnk[y])par[x] = y;
    else par[y] = x;
    if(rnk[x] == rnk[y])++rnk[x];
}

int main(){
    uread(N);
    uf(N);
    for(int i = 0; i < N; ++i){
        uread(a);
        uread(b);
        c[i] = make_pair(a, b);
        x[i] = make_pair(a, i);
        y[i] = make_pair(b, i);
    }
    a = 0;
    sort(x, x + N);
    sort(y, y + N);
    for(int i = 0; i < N - 1; ++i){
        v.push_back(make_pair(x[i + 1].first - x[i].first, make_pair(x[i + 1].second, x[i].second)));
        v.push_back(make_pair(y[i + 1].first - y[i].first, make_pair(y[i + 1].second, y[i].second)));
    }
    sort(v.begin(), v.end());
    for(auto P : v){
        if(fnd(P.second.first) != fnd(P.second.second)){
            a += P.first;
            unon(P.second.first, P.second.second);
        }
    }
    cout << a << endl;
    return 0;
}
