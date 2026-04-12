#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<int> d;
    for (int i = 0; i < a; i++) {
        int b;
        cin >> b;
        if (d.size()==0) {
            d.push_back(b);
            continue;
        }
        if(d.at(d.size()-1)>=b) d.push_back(b);
        else {

            int right = d.size();
            int left = -1;
            while (abs(right - left) > 1) {
                int mid = left + (right - left) / 2;

                if (d.at(mid)<b) right = mid;
                else left = mid;

            }
            d.at(right) = b;
        }
    }    
    cout << d.size() << endl;
}