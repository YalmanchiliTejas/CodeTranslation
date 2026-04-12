#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;

    char board[h][w];
    rep(i, h) {
        rep(j, w) {
            char a;
            cin >> a;
            board[i][j] = a;
        }
    }

    int check[h][w];
    rep(i, h) {
        rep(j, w) {
            check[i][j] = 1;
        }
    }
    
    rep(i, h) {
        int flag = 1;

        rep(j, w) {
            if(board[i][j] == '#') {
                flag = 0;
            }
        }

        if(flag) {
            rep(j, w) {
                check[i][j] = 0;
            }
        }
    }

    rep(j, w) {
        int flag = 1;

        rep(i, h) {
            if(board[i][j] == '#') {
                flag = 0;
            }
        }

        if(flag) {
            rep(i, h) {
                check[i][j] = 0;
            }
        }
    }

    rep(i, h) {
        int flag = 0;

        rep(j, w) {
            if(check[i][j]) {
                cout << board[i][j];
                flag = 1;
            }
        }

        if(flag || i == h-1) {
            cout << "\n";
        }
    } 

    return 0;
}