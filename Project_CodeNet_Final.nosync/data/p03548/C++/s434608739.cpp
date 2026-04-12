#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll x, y, z;
    cin >> x >> y >> z;
    ll ans = (x-z)/(y+z);
    cout << ans;
}