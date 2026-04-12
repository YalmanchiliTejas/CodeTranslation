// 177

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    int n;
    cin >> n;
    vector<ll> v(n), sum(n, 0);
    ll buf, ans=0, tmp;
    cin >> buf;
    v.at(0) = buf;
    sum.at(0) = buf;
    for(int i=1; i<n; i++){
        cin >> buf;
        v.at(i) = buf;
        sum.at(i) = (sum.at(i-1) + buf)%NUM;
    }
    for(int i=n-1; i>0; i--){
        tmp = (sum.at(i-1) * v.at(i))%NUM;
        ans = (ans + tmp)%NUM;
    }
    cout << ans << endl;
    return 0;
}
