#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
using namespace std;

int main() {
    char c;
    cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}