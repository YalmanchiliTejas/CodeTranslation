#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){

    int n, m; cin >> n >> m;

    int mat[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mat[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;

        mat[t1-1][t2-1] = 1;
        mat[t2-1][t1-1] = 1;
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << mat[i][j];
    //     }
    //     cout << endl;
    // }

    int perm[n-1];
    for(int i=1; i<n; i++){
        perm[i-1] = i;
    }

    int cnt = 0;
    // int cnt2 = 0;
    do{
        // cnt2++;
        int now = 0;
        bool flag = false;
        for(int i=0; i<n-1; i++){
            int to = perm[i];
            if(mat[now][to] == 0){
                break;
            }
            if(i == n-2){
                flag = true;
            }
            now = to;
        }
        if(flag) cnt++;
    } while(next_permutation(perm, perm+n-1));

    // cout << cnt2 << endl;
    cout << cnt;

    return 0;
}