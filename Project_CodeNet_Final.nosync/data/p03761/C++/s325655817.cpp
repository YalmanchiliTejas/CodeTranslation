#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;

typedef unsigned long long ull;
const int N_MAX = 1e6;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    REP(i, n){
        cin >> S[i];
    }
    vector< vector<int> > alphabets;
    REP(i, n){
        vector<int> vec(26, 0);
        alphabets.push_back(vec);
    }
    REP(i, n){
        REP(j, S[i].size()){
            alphabets[i][(int)S[i][j] - 97]++;
        }
    }
    vector<int> res(26);
    REP(j, 26){
        int mini = 100;
        REP(i, n){
            mini = min(alphabets[i][j], mini);
        }
        res[j] = mini;
    }
    REP(j, 26){
        REP(i, res[j]){
            putchar(j+97);
        }
    }
    cout << endl;
    return 0;
}