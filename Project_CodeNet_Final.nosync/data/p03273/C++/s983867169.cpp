#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin,(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    REP(i,h){
        REP(j,w)cin >> a[i][j];
    }
    bool change=true;
    bool end = false;
    while(!end){
        end = true;
        REP(i,h){
            change = true;
            REP(j,w){
                if(!(a[i][j] == '.' || a[i][j] == ',')){
                    change = false;
                }
            }
            if(change){
                end = false;
                REP(j,w){
                    a[i][j]=',';
                }
            }
        }
        REP(i,w){
            change = true;
            REP(j,h){
                if(!(a[j][i] == '.' || a[j][i] == ',')){
                    change = false;
                }
            }
            if(change){
                end = false;
                REP(j,h){
                    a[j][i] = ',';
                }
            }
        }
        end = true;
    }
   
    bool flag;
    REP(i,h){
        flag = false;
        REP(j,w){
            if(a[i][j]!=','){
                cout << a[i][j];
                flag = true;
            }
        }
        if(flag)
        cout << endl;
    }
    

    return 0;
}