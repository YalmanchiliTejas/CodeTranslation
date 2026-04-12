#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll h,w;cin>>h>>w;
    vector<vector<char>> v(h, vector<char> (w));
    REP(i,h){
        REP(j,w){
            cin>>v[i][j];
        }
    }
    vector<ll> line, column;
    REP(i,h){
        REP(j,w){
            if(v[i][j]=='#'){
                line.push_back(i);
                break;
            }
        }
    }
    REP(i,w){
        REP(j,h){
            if(v[j][i]=='#'){
                column.push_back(i);
                break;
            }
        }
    }
    ll l=SIZE(line), c=SIZE(column);
    REP(i,l){
        ll a=line[i];
        REP(j,c){
            ll b=column[j];
            cout<<v[a][b];
            if(j==c-1){
                cout<<endl;
            }
        }
    }
    return 0;
}
