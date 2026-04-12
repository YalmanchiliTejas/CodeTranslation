#include "bits/stdc++.h"
#include <math.h>
#include <time.h>
using namespace std;
const long long mod = 1000000007;
#define dump(x)                             \
    if (dbg) {                              \
        cout << #x << " = " << (x) << endl; \
    }
bool dbg = false;
long long gcd(long long a, long long b){
   if (a % b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a % b));
   }
}
long long lcm(long long a, long long b){
   return (a / gcd(a, b))* b;
}
//---------------------------------------------------------------------------------------------------
/*ここからいじる*/
//---------------------------------------------------------------------------------------------------

void solve(){
}
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<string> >data(h, vector<string>(w));
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            data.at(i).at(j) = s.at(j);
        }
    }
    solve();
    vector<bool>hn(h);
    vector<bool>wn(w);
    for (int i = 0; i < h; i++){
        bool ck = true;
        for(int j = 0; j < w; j++){
            if(data.at(i).at(j) == "#"){
                ck = false;
            }
        }
        if(ck)
        hn.at(i) = true;
    }
    for(int i = 0; i < w; i++){
        bool ck = true;
        for(int j = 0; j < h; j++){
            if(data.at(j).at(i) == "#"){
                ck = false;
            }
        }
        if(ck){
            wn.at(i) = true;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!hn.at(i) && !wn.at(j)){
                cout << data.at(i).at(j);
            }
            if(j == w - 1 && !hn.at(i)){
                cout << endl;
            }
        }
    }
    return 0;
}

