#include<iostream>
#include<string>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    bool flag;
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    while(true){
        rep(i,h){
            flag=true;
            rep(j,w){
                if(a[i][j]=='#'){
                    flag = false;
                }
            }
            if(flag){
                rep(j,w){
                    a[i][j] =' ';
                }
                continue;
            }
        }
        rep(j,w){
            flag=true;
            rep(i,h){
                if(a[i][j]=='#'){
                    flag = false;
                }
            }
            if(flag){
                rep(i,h){
                    a[i][j] =' ';
                    continue;
                }
            }
        }
        break;
    }
    rep(i,h){
        flag =false;
        rep(j,w){
            if(a[i][j]!=' '){
                cout << a[i][j];
                flag=true;
            }
        }
        if(flag){
            printf("\n");
        }
    }
}