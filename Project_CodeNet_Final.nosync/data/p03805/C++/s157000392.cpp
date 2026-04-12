#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{   
    //ノード数n,エッジ数m
    ll n,m; cin >> n >> m;
    vector<vector<ll> > c(n,vector<ll>(n,0));
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        c[a][b] = 1;
    }
    vector<ll> d(n);
    for(int i=0;i<n;i++)d[i]=i;
    int count = 0;
    do{
        bool isres = true;
        if(c[0][d[1]] == 0 && c[d[1]][0] == 0)
            isres = false;
        for(int i=1;i<n-1;i++){
            if(c[d[i]][d[i+1]] == 0 && c[d[i+1]][d[i]] == 0){
                isres = false;
                break;
            }
        }
        if(isres)count++;
    }while(next_permutation(d.begin()+1,d.end()));
    cout << count << endl;
}
    