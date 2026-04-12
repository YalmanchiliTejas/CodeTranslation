#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define vii vector<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;

string yn(bool x){
    return x ? "Yes" : "No";
}



int main(){
    int h,w; cin >> h >> w;
    string cell[h];
    rep(i,h) cin >> cell[i];
    
    bool ans[h][w];
    rep(i,h) rep(j,w) ans[i][j] = 1;
    
    rep(i,h){
        bool check = 1;
        
        rep(j,w){
            if(cell[i][j] == '#') check = 0;
        }
        if(check) rep(j,w) ans[i][j] = 0;
    }
    rep(i,w){
        bool check = 1;
        rep(j,h){
            if(cell[j][i] == '#') check = 0;
        }
        if(check) rep(j,h) ans[j][i] = 0;
    }
    
    rep(i,h){
        bool line = 0;
        rep(j,w){
            if(ans[i][j]) {
                cout << cell[i][j];
                line = 1;
            }
            
        }
        if(line)cout << endl;
    }
    

}





