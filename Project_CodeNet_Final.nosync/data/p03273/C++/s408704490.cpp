#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
#define rep2(i, N, s) for(int (i) = (s); (i) < (N) + (s); (i) ++)
#define rrep(i, N) for(int (i) = (N) - 1; (i) >= (0); (i) --)
#define rrep2(i, N, s) for(int (i) = (s); (i) >= (s) - (N) + 1; (i) --)
#define INF 1e9

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef  pair<int, int> pint;

int main(){
    int H, W;
    cin >> H >> W;
    char mas[100][100];
    rep(i, H){
        rep(j, W){
            cin >> mas[i][j];
        }
    }
    vector<int> rows;
    rep(i, H){
        bool flag = false;
        rep(j, W){
            if(mas[i][j] == '#'){
                flag = true;
                break;
            }
        }
        if(flag){
            rows.push_back(i);
        }
    }

    vector<int> clms;
    rep(i, W){
        bool flag = false;
        rep(j, H){
            if(mas[j][i] == '#'){
                flag = true;
                break;
            }
        }
        if(flag){
            clms.push_back(i);
        }
    }

    rep(i, rows.size()){
        rep(j, clms.size()){
            int row = rows[i];
            int clm = clms[j];
            cout << mas[row][clm];
        }
        cout << endl;
    }
    return 0;
}
