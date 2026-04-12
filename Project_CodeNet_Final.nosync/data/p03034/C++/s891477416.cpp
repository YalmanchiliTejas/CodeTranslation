#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> s(n);
    for(int i = 0; i < n; ++i){
        long long si;
        cin >> si;
        s.at(i) = si;
    }

    long long ans = 0;
    for(int c = 1; c < n - 1; ++c){
        long long tmp = 0;
        for(int k = 1; (k + 1) * c < n - 1; ++k){
            const long long a = n - 1 - k * c;
            if(a % c == 0 && (a / c <= k)){
                break;
            }
            tmp += s.at(k * c) + s.at(n - 1 - k * c);
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
