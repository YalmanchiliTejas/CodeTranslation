#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
typedef pair<int,int> P;
#define mod 1000000007

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>m(h,vector<char>(w));
    vector<vector<bool>>tf(h,vector<bool>(w,true));
    rep(i,h){
        int count=0;
        rep(j,w){
            char c;
            cin>>c;
            m[i][j]=c;
            if(c=='.') count++;
        }
        if(count==w){
            rep(j,w) tf[i][j]=false;
        }
    }

    rep(j,w){
        int count=0;
        rep(i,h){
            if(m[i][j]=='.') count++;
        }
        if(count==h){
            rep(i,h) tf[i][j]=false;
        }
    }


    rep(i,h){
        int x=0;
        rep(j,w){
            if(tf[i][j]==true) {
                cout << m[i][j];
                x++;
            }
        }
        if(x>0)cout << endl;
    }
    
    return 0;
}
