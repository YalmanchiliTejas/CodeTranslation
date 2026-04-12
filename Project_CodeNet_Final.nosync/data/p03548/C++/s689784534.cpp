#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
    
using namespace std;    
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){

    ll x, y, z;
    cin >> x >> y >> z;

    ll cnt = 0;
    while(true){
        if( (cnt + 1) * z + cnt * y <= x){
            cnt ++;
        }
        else{
            break;
        }
    }
    cout << cnt - 1 << endl;
}