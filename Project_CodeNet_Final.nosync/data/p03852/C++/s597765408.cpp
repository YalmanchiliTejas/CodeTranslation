#include<bits/stdc++.h>

#define REPI(i, n) for(int i = 0; i < n; i++)
#define REPJ(j, n) for(int j = 0; j < n; j++)

using ll = long long;
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c; cin >> c;
    cout << (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'
            ? "vowel" : "consonant");
}
