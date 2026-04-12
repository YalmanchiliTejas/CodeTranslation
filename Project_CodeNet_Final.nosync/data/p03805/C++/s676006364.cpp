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
int n, m, cnt;
vector<pair<int, int> >p(100);
vector<vector<bool> >data(9, vector<bool>(9));
void solve(){
    vector<int>array(n);
    for(int i = 0; i < n; i++){
        array.at(i) = i;
    }
    do{
        for(int i = 0; i < n - 1; i++){
            if(i == 0){
                if(array.at(i) != 0){
                    break;
                }
            }
            if(!data.at(array.at(i)).at(array.at(i + 1))){
                break;
            }
            if(i == n - 2){
                cnt++;
            }
        }
    }while(next_permutation(array.begin(), array.end()));
    cout << cnt << endl;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> p.at(i).first >> p.at(i).second;
        p.at(i).first--;
        p.at(i).second--;
    }
    for(int i = 0; i < m; i++){
        data.at(p.at(i).first).at(p.at(i).second) = true;
        data.at(p.at(i).second).at(p.at(i).first) = true;
    }
    cnt = 0;
    solve();
    return 0;
}

