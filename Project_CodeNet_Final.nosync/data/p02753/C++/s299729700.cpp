#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ios>//左右揃え
#include<iomanip>//setwで幅指定

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007LL

int main(void) {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}