#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <numeric>
#include <climits>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, k, n) for(int i = (k); i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int ans = 0;
    int cnt = 0;
    while(ans != X){
        ans += Z;
        ans += Y;
        cnt++;
        if(X - ans < Y + 2 * Z)
            break;
    }
    cout << cnt << endl;
    return 0;
}