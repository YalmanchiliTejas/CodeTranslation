#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, g, b, answer;
    cin >> r >> g >> b;
    string r_, g_ , b_, sum;
    r_ = to_string(r);
    g_ = to_string(g);
    b_ = to_string(b);
    sum = r_ + g_ + b_;
    answer = stoi(sum);
    if (answer % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}