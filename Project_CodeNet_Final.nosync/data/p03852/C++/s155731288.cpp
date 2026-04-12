#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}

int main(){

    char c;

    cin >> c;

    cout << (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? "vowel" : "consonant") << endl;

    return 0;
}