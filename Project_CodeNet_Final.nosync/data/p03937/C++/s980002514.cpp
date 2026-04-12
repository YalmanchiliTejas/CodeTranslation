#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    int H,W; cin>>H>>W;
    vector<vector<char>>a(H,vector<char>(W));
    rep(i,H){
        rep(j,W)cin>>a[i][j];
    }
    int cnt=0;
    bool judge;
    bool out;
    int b;
    rep(i,H){
        judge=false;
        out=false;
        for(int j=cnt;j<W;j++){
            while(a[i][j]=='#'){
                j++;
                cnt++;
                if(judge){
                    cout<<"Impossible"<<endl;
                    return 0;
                }
                  b=cnt;
                if(j==W){
                    out=true;
                    break;
                }
              
            }
            judge=true;
            if(i<=H-2){
                if(a[i+1][b-1]!='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
            }
            if(out)break;
        }
        if(i<=H-2){
            rep(k,cnt-1){
            if(a[i+1][k]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
        }
    }
    cout<<"Possible"<<endl;
}