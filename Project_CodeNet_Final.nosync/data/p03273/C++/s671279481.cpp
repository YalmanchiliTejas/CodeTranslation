#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    vector<int> b;
    vector<int> c;
    vector<pair<int, int>> p;
    rep(i,h)rep(j,w){
        cin >> a[i][j];
    }
    rep(i,h){
        bool flag = true;
        rep(j,w){
            if(a[i][j] == '#'){
                flag = false;
                break;
            }
        }
        if(flag){
            rep(k,w){
                pair<int, int> ps = {i, k};
                p.pb(ps);
            }
        }
    }
    rep(i,w){
        bool flag = true;
        rep(j,h){
            if(a[j][i] == '#'){
                flag = false;
                break;
            }
        }
        if(flag){
            rep(k,h){
                pair<int, int> ps = {k, i};
                p.pb(ps);
            }
        }
    }
    rep(i,h){
        int count = 0;
        rep(j,w){
            bool flag = true;
            rep(k,p.size()){
                if(p[k].first == i && p[k].second == j){
                    flag = false;
                    count++;
                    break;
                }
            }
            if(flag){
                cout << a[i][j];
            }
        }
        if(count != w) cout << endl;
    }
}