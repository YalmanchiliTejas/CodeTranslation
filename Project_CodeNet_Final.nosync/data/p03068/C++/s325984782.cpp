#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using myui = uint64_t;
using myint = int64_t;

template<typename T>
T diff(const T& a, const T& b) {
    return a > b ? a - b : b - a;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    {
        myui n, k;
        string s;
        cin >> n >> s >> k;
        for(auto& c : s) {
            cout << (c == s[k-1] ? c : '*');
        }
        cout << endl;
    }

    return 0;
}
