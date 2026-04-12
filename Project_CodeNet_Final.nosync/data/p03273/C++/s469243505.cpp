#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#include<stack>
#include<map>
#include<queue>
#include<set>
#define int long long
using namespace std;
const int INF = 1e10;
const int ZERO = 0;

signed main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> vec(H,vector<char>(W));
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            cin >> vec.at(i).at(j);
        }
    }
    vector<bool> A(H);
    vector<bool> B(W);
    for(int i = 0; i < H;i++) {
        bool C = false;
        for(int j = 0;j < W;j++) {
            if(vec.at(i).at(j) == '#') {
                C = true;
            }
        }
        if(C == true) {
            A.at(i) = true;
        }
    }
    for(int i = 0;i < W;i++) {
        bool C = false;
        for(int j = 0;j < H;j++) {
            if(vec.at(j).at(i) == '#') {
                C = true;
            }
        }
        if(C == true) {
            B.at(i) = true;
        }
    }
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            if(A.at(i) == true && B.at(j) == true) {
                cout << vec.at(i).at(j);
            }
          	if(j == W - 1 && A.at(i) == true) {
            cout << endl;
        	}
        }
    }
}