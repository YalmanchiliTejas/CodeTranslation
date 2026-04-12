//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    int h,w;cin>>h>>w;
    vector<vector<char>>a(h,vector<char>(w));
    rep(i,h){
        rep(j,w)cin>>a[i][j];
    }
    int cnt=0;
    rep(i,h){
        for(int j=cnt;j<w;j++){
            while(a[i][j]=='#'){
                a[i][j]='.';
                j++;
            }
            cnt=j-1;
            break;
        }
    }
      rep(i,h){
        rep(j,w){
            if(a[i][j]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
}



