#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める
bool is_dot(vector<char> a, int w){
    rep(i,w){
        if(a[i] != '.' && a[i] != 'a') return false;
    }
    return true;
}

bool is_wdot(vector<vector<char>> a, int h, int w){
    rep(j,h){
        if(a[j][w] != '.' && a[j][w] != 'a') return false;
    }
    return true;
}

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    rep(i,h){
        if(is_dot(a[i],w)){
            rep(j,w){
                a[i][j] = 'a';
            }
        }
    }
    rep(i,w){
        rep(j,h){
            if(is_wdot(a,h,i)){
                rep(k,h){
                    a[k][i] = 'a';
                }
            }
        }
    }
    bool flag;
    rep(i,h){
        flag = false;
        rep(j,w){
            if(a[i][j] != 'a'){
                cout <<  a[i][j];
                flag = true;
            } 
        }
        if(flag) cout << endl;
    }
    return 0;
}