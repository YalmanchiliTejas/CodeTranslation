#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    map<ll,ll> mp;
    vector<ll> mod;
    for(int i = 0;i < n;i++){
        mp[x]++;
        if(mp[x] >= 2){
            ll sit = 0;
            ll res = 0;
            for(int j = 0;j < mod.size();j++){
                if(mod[j] == x){
                    sit = j;
                    break;
                }
                res += mod[j];
            }
            ll kaisuu = n - sit;
            ll roop = 0;
            for(int j = sit;j < mod.size();j++)roop += mod[j];
            res += roop * (kaisuu / (mod.size() - sit));
            kaisuu %= (mod.size() - sit);//はしたの個数
            for(int j = sit;j < sit + kaisuu;j++)res += mod[j];
            cout << res << endl;
            return 0;
        }
        mod.push_back(x);
        if(i == n - 1){
            ll res = 0;
            for(int j = 0;j < n;j++)res += mod[j];
            cout << res << endl;
            return 0;
        }
        x *= x;
        x %= m;
    }
}