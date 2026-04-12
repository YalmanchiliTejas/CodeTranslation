#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    char A[10][10];
    for(int i=0; i<10; i++)
        fill_n(A[i], 10, '.');

    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
            cin >> A[i][j];

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(A[i][j] == '.') continue;
            if((A[i-1][j] == '#' && A[i][j-1] == '#') ||
                    (A[i+1][j] == '#' && A[i][j+1] == '#')){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}
