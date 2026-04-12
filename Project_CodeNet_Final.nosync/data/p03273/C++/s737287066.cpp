#include <cstdio>
#include <string>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i=a;i<n;++i)
#define repeq(i, a, n) for(int i=a;i<=n;++i)
#define repi(m, itr) for (auto itr = m.begin();itr != m.end();++itr)
#define per(i, a, n) for (int i=n-1; i>=a;--i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

// 
int H, W;
char a[110][110];
vector<vector<char>> ans;

int main(){
    cin >> H >> W;
    rep(i, 0, H){
        rep(j, 0, W){
            cin >> a[j][i];
        }
    }
    
    rep(i, 0, H){
        bool del = true;
        rep(j, 0, W){
            if(a[j][i] == '#'){
                del = false;
            }
        }
        if(del){
            rep(j, 0, W){
                a[j][i] = 'd';
            }
        }
    }
    rep(j, 0, W){
        bool del = true;
        rep(i, 0, H){
            if(a[j][i] == '#'){
                del = false;
            }
        }
        if(del){
            rep(i, 0, H){
                a[j][i] = 'd';
            }
        }
    }
    
    int hs = 0;
    int ws = 0;
    rep(i, 0, H){
        ws = 0;
        vector<char> tmp;
        int plshs = false;
        rep(j, 0, W){
            if(a[j][i] != 'd'){
                tmp.push_back(a[j][i]);
                ++ws;
                plshs = true;
                cout << a[j][i];
            }
        }
        ans.push_back(tmp);
        if(plshs){
            cout << endl;
        }
    }
    return 0;
}


