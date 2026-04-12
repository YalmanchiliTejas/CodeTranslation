#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> data(h, vector<char>(w));
    vector<bool> x(h,false),y(w,false);

    rep(i,h){
        rep(j,w){
            cin >> data[i][j];
            if(data[i][j]=='#'){
                x[i]=true;
                y[j]=true;
            }
        }
    }

    rep(i,h){
        if(x[i]){
            rep(j,w){
                if(y[j]){
                    cout << data[i][j];
                }
            }
        cout << endl;
        }
    }

    return 0;
}

