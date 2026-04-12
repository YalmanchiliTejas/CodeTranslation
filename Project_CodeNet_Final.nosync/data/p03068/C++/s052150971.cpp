#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;


#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())
//vvintを作る　マクロで　 #define vvint(N,M) vector<vector<int>>

using namespace std;


int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    string S;
    cin >> N >> S >> K;

    char c =  S[K-1];
    for(int i = 0; i < N;i++){
        if(S[i] != c){
            S[i]='*';
        }
    }
    cout << S << endl;

    

    return 0;
}