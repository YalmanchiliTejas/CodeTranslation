#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int h,w;
    cin>>h>>w;
    char a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    vector<bool> vertical(w,false);
    vector<bool> horizontal(h,false);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!horizontal[i] && a[i][j]=='#'){
                horizontal[i]=true;
            }
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(!vertical[i] && a[j][i]=='#'){
                vertical[i]=true;
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(horizontal[i] && vertical[j]){
                cout<<a[i][j];
            }
        }
        if(horizontal[i]) cout<<endl;
    }
}