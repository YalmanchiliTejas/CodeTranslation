#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;

signed main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> a(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int k=0;k<W;k++){
            cin >> a[i][k];
        }
    }
    
    map<int,int> yoko;
    map<int,int> tate;
    for(int i=0;i<H;i++){
        for(int k=0;k<W;k++){
            if(a[i][k]=='.'){
                yoko[i]++;
                tate[k]++;
            }
        }
    }
    
    int cnt = 0;
    for(int i=0;i<H;i++){
        for(int k=0;k<W;k++){
            if(yoko[i]==W) continue;
            if(tate[k]==H) continue;
            cout << a[i][k];
            cnt++;
        }
        if(cnt>0) cout << endl;
        cnt = 0;
    }
    
    return 0;
}
