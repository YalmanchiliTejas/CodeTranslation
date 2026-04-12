#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <functional>
#include <queue>
#include <map>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int INF = 100000000;

int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    REP(i, h){
        REP(j, w){
            cin >> a[i][j];
        }
    }
    vector<bool> d(h, false);
    vector<bool> f(w, false);
    REP(i, h){
        int count = 0;
        REP(j, w){
            if(a[i][j] == '#'){
                break;
            }else{
                count++;
            }
            if(count == w){
                d[i] = true;
            }
        }
    }
    REP(i, w){
        int count = 0;
        REP(j, h){
            if(a[j][i] == '#'){
                break;
            }else{
                count++;
            }
            if(count == h){
                f[i] = true;
            }
        }
    }
    REP(i, h){
        REP(j , w){
            if(!d[i] && !f[j]){
                cout << a[i][j];
            }
        }
        if(!d[i]){
            cout << endl;
        }
    }
    return 0;
}