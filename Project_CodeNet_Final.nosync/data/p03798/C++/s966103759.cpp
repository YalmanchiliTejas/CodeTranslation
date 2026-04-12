#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

int main() {
    int N; cin >> N;
    string S1; cin >> S1;
    string S = S1 + S1;

    vector<int> res(2*N,0);
    //0...羊 1...狼
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 2*N; i++) res[i] = 0;
        res[0] = k&1;
        res[1] = (k&2)/2;

        for (int i = 2; i < N; i++) {
            if (S[i-1] == 'o') res[i] = res[i-2] ^ res[i-1];
            else res[i] = !(res[i-2] ^ res[i-1]);
        }
        bool flag = true;
        
        if (S[0] == 'o' && (res[1] != res[N-1] ^ res[0])) flag = false;
        if (S[0] == 'x' && (res[1] == res[N-1] ^ res[0])) flag = false;
        if (S[N-1] == 'o' && (res[0] != res[N-2] ^ res[N-1])) flag = false;
        if (S[N-1] == 'x' && (res[0] == res[N-2] ^ res[N-1])) flag = false;

        if (flag) {
            for (int i = 0; i < N; i++) {
                if (res[i] == 0) cout << 'S';
                else cout << 'W';
            } 
            cout << endl; return 0;
        }
    }
    cout << "-1\n";

    

}