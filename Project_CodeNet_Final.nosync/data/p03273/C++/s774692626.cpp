#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
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

using namespace std;

int H,W;
char s;
int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    char table[H][W];
    bool h[H];
    bool w[W];

    REP(i,H){
        h[i] = true;
        REP(j,W){
            cin >> s;
            table[i][j] = s;
            if(s == '#' && h[i]) h[i] = false; 
        }
    }
    REP(i,W){
        w[i] = true;
        REP(j,H){
            if(table[j][i] == '#' && w[i]) w[i] = false; 
        }
    }
    REP(i,H){
        REP(j,W){
            if(h[i]) table[i][j] = 'n';
        }
    }
    REP(i,W){
        REP(j,H){
            if(w[i]) table[j][i] = 'n';
        }
    }

     REP(i,H){
        REP(j,W){
            if(table[i][j] != 'n') cout << table[i][j];
        }
        if(!h[i]) cout << endl;
    }



    

    return 0;
}