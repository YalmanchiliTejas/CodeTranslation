#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(ll i = 0;i < h;i++){
        cin >> a[i];
    }

    vector<vector<bool>> ba1(h, vector<bool>(w, false)), ba2(h, vector<bool>(w, false));

    for(ll i = 0;i < h;i++){
        bool f = false;
        for(ll j = w - 1;j >= 0;j--){
            ba1[i][j] = f;
            if(a[i][j] == '#'){
                f = true;
            }
        }
    }

    for(ll i = 0;i < w;i++){
        bool f = false;
        for(ll j = h - 1;j >= 0;j--){
            ba2[j][i] = f;
            if(a[j][i] == '#'){
                f = true;
            }
        }
    }

    bool ans = true;
    for(ll i = 0;i < h;i++){
        for(ll j = 0;j < w;j++){
            if(a[i][j] == '#' && !(i == h - 1 && j == w - 1)){
                if(ba1[i][j] && ba2[i][j] || !ba1[i][j] && !ba2[i][j]){
                    ans = false;
                }
            }
        }
    }

    /*for(ll i = 0;i < h;i++){
        for(ll j = 0;j < w;j++){
            cout << ba1[i][j];
        }
        cout << endl;
    }
    
    for(ll i = 0;i < h;i++){
        for(ll j = 0;j < w;j++){
            cout << ba2[i][j];
        }
        cout << endl;
    }*/

    if(ans){
        cout << "Possible";
    }
    else{
        cout << "Impossible";
    }

    return 0;
    
}
