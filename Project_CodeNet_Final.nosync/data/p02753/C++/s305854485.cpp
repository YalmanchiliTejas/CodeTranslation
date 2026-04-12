#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    string s;
    cin >> s;
    auto itr = unique(begin(s), end(s));
    cout << (itr - begin(s) != 1 ? "Yes" : "No") << endl;
}
