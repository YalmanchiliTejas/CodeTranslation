#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int gyo,retu;
    cin >> gyo >> retu;
    vector<vector<char>> array(gyo,vector<char>(retu));
    rep(i,gyo){
        rep(j,retu){
            cin >> array[i][j];
        }
    }
    
    bool deleg[gyo],deler[retu];
    rep(i,gyo) deleg[i] = false;
    rep(i,retu) deler[i] = false;
    
    rep(i,gyo){
        rep(j,retu){
            if(array[i][j] == '#'){
                deleg[i] = true;
                break;
            }
        }
    }
    
    rep(i,retu){
        rep(j,gyo){
            if(array[j][i] == '#'){
                deler[i] = true;
                break;
            }
        }
    }
    bool sw = false;
    int size = array.at(0).size();
    rep(i,gyo){
        rep(j,retu){
            if(deleg[i] && deler[j]){
                cout << array[i][j];
                sw = true;
            }
            if(j == size - 1 && sw){
                cout << endl;
                sw = false;
            }
        }
    }
    return 0;
}