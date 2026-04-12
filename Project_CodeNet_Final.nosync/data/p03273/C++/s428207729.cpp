#include <iostream>
#include <numeric>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
#define INF 100000000
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define rep(i, n) for(int (i)=1; (i)<=(n); (i)++)
typedef pair<int, int> P;
typedef long long ll;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> a(H);

    for(int i=0; i<H; i++){
        cin >> a[i];
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i=0; i<H; i++){
        if(row[i]){
            for(int j=0; j<W; j++){
                if(col[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}