#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    string a = "AAA";
    string b = "BBB";
    if(s == a || s == b){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}