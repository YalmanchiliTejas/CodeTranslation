#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    long long int n;
    long long int sum = 0, res = 0;
    
    cin >> n;
    
    while(n--) {
        long long int temp;
        cin >> temp;
        res = (res + sum * temp) % 1000000007LL;
        sum = (sum + temp) % 1000000007LL;
    }
    
    cout << res;
    
    return 0;
}
