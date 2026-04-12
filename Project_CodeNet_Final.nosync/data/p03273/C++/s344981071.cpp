#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

int main(){
    int h,w;
    cin >> h >> w;
    
    vector<vector<char>> a(h,vector<char>(w));
    
    rep(i,h){
        rep(j,w) cin >> a[i][j];
    }
    
    vector<bool> height(h,false);
    vector<bool> width(w,false);
    
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#'){
                height[i] = true;
                width[j] = true;
            }
        }
    }
    
    rep(i,h){
        if(height[i]){
            rep(j,w){
                if(width[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}