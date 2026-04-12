#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define REP(i, n) for(int i=0; i<n; i++)

int H,W;
bool A[100][100];
int row[100];
int col[100];

int main(){
    cin >> H >> W;
    char a;
    REP(i, H){
        REP(k, W){
            cin >> a;
            if(a == '.'){
                A[i][k] = true;
                row[i]++;
                col[k]++;
            }
        }
    }

    REP(i, H){
        if(row[i] == W) continue;
        REP(k, W){
            if(col[k] == H) continue;
            if(A[i][k]) cout << ".";
            else cout << "#";
        }
        cout << endl;
    }
    return 0;
}
