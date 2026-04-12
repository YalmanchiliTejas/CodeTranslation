#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1, (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> array(h+2, vector<bool>(w+2, false));
    array[0][1] = true;
    array[h+1][w] = true;

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            char c;
            cin >> c;
            if(c == '#'){
                array[i][j] = true;
            }
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(array[i][j]){
                if(!((array[i-1][j] ^ array[i][j-1]) && (array[i+1][j] ^ array[i][j+1]))){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Possible" << endl;

    return 0;
}