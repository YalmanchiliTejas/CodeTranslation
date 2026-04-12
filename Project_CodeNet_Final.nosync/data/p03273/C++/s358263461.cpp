#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(ll i = 0;i < h;i++){
        cin >> s[i];
    }

    ll gyo = -1, re = -1;
    for(ll i = 0;i < h;i++){
        bool f = true;
        for(ll j = 0;j < w;j++){
            if(s[i][j] == '#'){
                f = false;
            }
        }
        if(f){
            for(ll j = 0;j < w;j++){
                s[i][j] = '0';
            }
        }
    }

    for(ll i = 0;i < w;i++){
        bool f = true;
        for(ll j = 0;j < h;j++){
            if(s[j][i] == '#') f = false;
        }
        if(f){
            for(ll j = 0;j < h;j++){
                s[j][i] = '0';
            }
        }
    }

    for(ll i = 0;i < h;i++){
        bool f = false;
        for(ll j = 0;j < w;j++){
            if(s[i][j] != '0'){
                f = true;
                cout << s[i][j];
            }
        }
        if(f){
            cout << "\n";
        }
    }

    return 0;
}