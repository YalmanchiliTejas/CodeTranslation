#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    char a[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j] == '#'){
                break;
            }
            if(j==W-1){
                for(int k = 0; k < W; k++){
                    a[i][k] = '@';
                }
            }
        }
    }
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            if(a[i][j] == '#'){
                break;
            }
            if(i==H-1){
                for(int k = 0; k < H; k++){
                    a[k][j] = '@';
                }
            }
        }
    }

    for(int i = 0; i < H; i++){
        bool newline = false;
        for(int j = 0; j < W; j++){
            if(a[i][j]!='@'){
                cout << a[i][j];
                newline = true;
            }
        }
        if(newline)
            cout << endl;
    }  
    return 0;
}