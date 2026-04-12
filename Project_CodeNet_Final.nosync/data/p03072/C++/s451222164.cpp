#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v(n);

    for(auto& i : v) cin >> i;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        bool ok = 1;
        for (int j = 0; j < i; ++j) {
            if(v[i] < v[j]) {
                ok = 0;
                break;
            }
        }
        cnt += ok;
    }
    cout << cnt << endl;
    return 0;
}