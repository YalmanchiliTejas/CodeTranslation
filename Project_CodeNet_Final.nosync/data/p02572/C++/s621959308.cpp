#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void){
    long n;
    cin >> n;
    vector<long> a;
    a.reserve(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    long ret = 0, mul = a[0];
    for(int i = 1; i < n; ++i){
        ret = (ret + (a[i] * mul) % 1000000007) % 1000000007;
        mul = (mul + a[i]) % 1000000007;
    }
    cout << ret << endl;
    return 0;
}