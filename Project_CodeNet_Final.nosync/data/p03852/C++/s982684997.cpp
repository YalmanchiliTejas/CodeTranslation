#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
using namespace std;

int main() {
    string c, x = "aeiou";
    cin >> c;
    if (x.find(c) < 5) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}