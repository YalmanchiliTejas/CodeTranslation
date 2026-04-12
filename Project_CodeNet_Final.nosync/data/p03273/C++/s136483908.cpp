
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; i++){
        cin >> s[i];
    }

    //同じ行に#があるかつ同じ列に#がある部分を出力する
    vector<bool> x(h,false);
    vector<bool> y(w,false);
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){
                x[i]=true;
                y[j]=true;
            }
        }
    }     
    rep(i,h){
        if(x[i]==true){
            rep(j,w){
                if(y[j]==true) cout << s[i][j];
            }
            cout << endl;
        }
    }   
    



}