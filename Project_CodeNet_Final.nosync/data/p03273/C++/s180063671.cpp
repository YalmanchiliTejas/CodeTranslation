#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;


int H,W;
vector<vector<char> > a;





int main()
{
    cin >> H >> W;
    a.assign(H,vector<char>(W, '.'));
    
    rep(i,H){
        rep(j,W) cin >> a[i][j];
    }
    
    rep(i,H){
        rep(j,W){
            if (a[i][j] == '.') {
                int h = 0;
                rep(k,H) if (a[k][j] != '#') h++;
                if(h==H) rep(k,H) a[k][j] = 'd';
                
                int w = 0;
                rep(k,W) if (a[i][k] != '#') w++;
                if(w==W) rep(k,W) a[i][k] = 'd';
                
            }
        }
    }
    /*
    cout << endl;
    rep(i,H){
        rep(j,W){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */
    rep(i,H){
        int aa = 0;
        rep(j,W){
            if (a[i][j] != 'd') {
                cout << a[i][j];
                aa += 1;
            }
        }
        if(aa >= 1) cout << endl;
        
    }
    
    
    
    
    return 0;
}

