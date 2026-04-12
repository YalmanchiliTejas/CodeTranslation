#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(ll i=0;i<(n);i++)

using namespace std;


int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h+1, vector<char>(w+1, '.'));
    rep(hx, h){
        rep(wx, w)  cin >> a[hx][wx];
    }

    set<pair<int, int>> closed;
    queue<pair<int, int>> que;
    que.push({0, 0});

    bool flag = false;

    vector<vector<char>> b(h+1, vector<char>(w+1, '.'));

    while(!que.empty()){
        pair<int, int> p = que.front();   que.pop();
        if(0 == closed.count(p)){
            int hx = p.first;
            int wx = p.second;
            b[hx][wx] = '#';
            if(hx == h-1 && wx == w-1){
                flag = true;
                break;
            }
            if(a[hx+1][wx] == '#' && a[hx][wx+1] == '#'){
                break;
            }
            if(a[hx+1][wx] == '#')  que.push({hx+1, wx});
            if(a[hx][wx+1] == '#')  que.push({hx, wx+1});
        }
        closed.insert(p);
    }

    [&]{
        rep(hx, h){
            rep(wx, w){
                if(a[hx][wx] != b[hx][wx]){
                    flag = false;
                    return;
                }
            }
        }
    }();

    if(flag)    cout << "Possible" << endl;
    else        cout << "Impossible" << endl;
    

    return 0;
}

