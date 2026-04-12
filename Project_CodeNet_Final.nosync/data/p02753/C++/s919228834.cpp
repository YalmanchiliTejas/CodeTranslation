#include <bits/stdc++.h>
using namespace std;

const int N = 40000 + 7;

int a[N], b[N];



int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str; cin >> str;
    if(str[1] == str[0] && str[1] == str[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}
