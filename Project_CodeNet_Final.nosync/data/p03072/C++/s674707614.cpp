#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

namespace test {
std::string to_string(char val) {
    return std::string(1, val);
    // return std::string{val};
}
}  // namespace test

using namespace std;

int main(void) {
    int n; cin >> n; int *h; h = new int[n]; for(int i = 0; i < n; i++) cin >> h[i];
    int result = 0;
    int maxHeight = 0;
    for(int i = 0; i < n; i++){
        if(h[i] >= maxHeight){
            result++;
            maxHeight = h[i];
        }
    }

    cout << result << endl;

    return 0;
}