#include <algorithm>
#include <iostream> //標準入出力
#include <fstream>  //ファイルでの入出力
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <utility> //pair
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000000007
#define pair(a) pair<a,a>

void _main(){
    ll out = 0;
    ll n; cin >> n;
    vector<ll>  as(n);
    ll sum=0;
    rep(i,n) {
        cin >> as[i];
        sum+=as[i];
        sum%=MAX;
    }
    rep(i,n-1){
        sum = (sum - as[i] + MAX)%MAX;
        out += (as[i]*sum)%MAX;
        out %= MAX;
    }
    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}