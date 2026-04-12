#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    char a;
    cin >> a;

    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') cout << "vowel" << endl;
    else cout << "consonant" << endl;

    return 0;
    
}