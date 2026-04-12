#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
using namespace std;
typedef long long int ll;

#define MOD 998244353

int main(){
    ll h,w;
    cin >> h >> w;
    string x[h];
    bool ww[w],hh[h];
    for (ll i=0;i<w;i++)ww[i]=true;
    for (ll i=0;i<h;i++)hh[i]=true;
    for (ll i=0;i<h;i++){
        cin >> x[i];
    }
    for (ll i=0;i<h;i++){
        for (ll j=0;j<w;j++){
            if (x[i][j]=='#')break;
            if (j==w-1){
                hh[i]=false;
            }
        }
    }
    for (ll i=0;i<w;i++){
        for (ll j=0;j<h;j++){
            if (x[j][i]=='#')break;
            if (j==h-1){
                ww[i]=false;
            }
        }
    }
    for (ll i=0;i<h;i++){
        for (ll j=0;j<w;j++){
            if (ww[j] && hh[i]){
                cout << x[i][j];
            }
        }
        if (hh[i])cout << endl;
    }
    return 0;
}


