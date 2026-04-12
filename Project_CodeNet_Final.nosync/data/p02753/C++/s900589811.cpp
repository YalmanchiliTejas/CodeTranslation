#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >>s;

    int sum =0;
    for(char c : s)
        sum += c;

    printf("%s\n",sum % 'B' == 0 || sum % 'A' == 0 ? "No" : "Yes");

    return 0;
}

