#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<tuple>
#include<utility>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define enter "\n"

typedef long long ll;


int abc107_b(){
    //入力
    int h,w;
    cin >> h >> w;
    vector<string> v(h);
    REP(i,h){
        cin >> v[i];
    }

    //処理
    vector<bool> row(h,false);
    vector<bool> column(w,false);
    REP(i,h){
        REP(j,w){
            if(v[i][j] == '#'){
                row[i] = true;
                column[j] = true;
            }
        }
    }
    
    //出力
    REP(i,h){
        if(row[i]){
            REP(j,w){
                if(column[j]){
                    cout << v[i][j];
                }
            }
            cout << enter;
        }
    }
    
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    abc107_b();
    return 0;
}
