#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    string t;
    rep(i,w) t += '.';

    for(int i=0; i<h; ++i){
        if(t == a[i]){
            a.erase(a.begin()+i);
            i = -1;
            --h;
        }
    }
    
    for(int j=0; j<w; ++j){
        bool can = true;
        for(int i=0; i<h; ++i){
            if(a[i][j] != '.') can = false;
        }
        if(can){
            for(int i=0; i<h; ++i) a[i].erase(j,1);
            j = -1;
            --w;
        }
    }
    rep(i,h) cout(a[i]);


    return 0;
}