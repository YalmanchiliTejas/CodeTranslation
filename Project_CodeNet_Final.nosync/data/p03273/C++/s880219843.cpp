#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = (n-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long

int main(){
    int H, W; cin >> H >> W;
    vector<char> a[105];
    vector<bool> hor, ver;
    
    rep(i, H){
        string s; cin >> s;
        bool flag = true;
        rep(j, W){
            if(s[j] == '#') flag = false;
            a[j].push_back(s[j]);
        }
        hor.push_back(flag);
    }

    rep(j, W){
        bool flag = true;
        rep(i, H){
            if(a[j][i] == '#') flag = false;
        }
        ver.push_back(flag);
    }

    rep(i, H){
        rep(j, W){
            if(!hor[i] && !ver[j]){
                cout << a[j][i];
            }
        }
        if(!hor[i]) cout << endl;
    }
}