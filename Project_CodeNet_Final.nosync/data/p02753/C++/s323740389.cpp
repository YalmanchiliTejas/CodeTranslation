#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

string s;
bool flag0, flag1;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') flag0 = true;
        else flag1 = true;
    }
    if (flag0 && flag1) cout << "Yes" << E;
    else cout << "No" << E;
    //system("pause");
    return 0;
}