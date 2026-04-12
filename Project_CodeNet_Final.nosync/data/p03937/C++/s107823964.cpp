#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int h,w;
    cin >> h >> w;
    int cnt=0;
    vector<string> mappu(h);
    rep(i,h) cin >> mappu[i];
    rep(i,h){
        rep(j,w){
            if(mappu[i][j] == '#') cnt++;
        }
    }
    if(cnt == h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" <<endl;
    
    
}