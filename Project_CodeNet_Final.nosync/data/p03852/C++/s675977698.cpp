#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    char c;
    cin >> c;
    string a = "aeiou";
    string ans = "consonant";

    rep(i, a.size()){
        if (c==a[i]){
            ans = "vowel";
            break;
            }
        }
        cout << ans << endl;
}