#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793

int main(){
    char c; cin >> c;
    string s = "aeiou";
    cout << (s.find(c) != string::npos ? "vowel" : "consonant") << endl;
}
