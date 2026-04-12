#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

int main(){

    int h, w;
    cin >> h >> w;

    vector<vector<int>> v(h, vector<int>(w));
    char tmpc;
    REP(i,h){
        REP(j,w){
            cin >> tmpc;
            if(tmpc == '.'){
                v[i][j] = 0;
            }else{
                v[i][j] = 1;
            }
        }
    }

    int tmpi=0;
    
    REP(i,h){
        REP(j,w){
            tmpi += v[i][j];
        }

        if(tmpi==0){
            REP(j,w){
                v[i][j]=2;
            }
        }
        tmpi = 0;
    
    }
    
    REP(i,w){
        REP(j,h){
            
            if(v[j][i]!=2){
                tmpi += v[j][i];
            }
        }

        if(tmpi==0){
            REP(j,h){
                v[j][i]=2;
            }
        }
        tmpi = 0;
    
    }

    REP(i,h){
        REP(j,w){
            
            
            if(v[i][j] == 0){
                cout <<'.';
            }else if(v[i][j]==1){
                cout<<'#';
            }
            
            
        }

        if(accumulate((v[i].begin()), (v[i].end()), 0)==2*w){
            continue;
        }

        cout << endl;
        
    }

    return 0;
}