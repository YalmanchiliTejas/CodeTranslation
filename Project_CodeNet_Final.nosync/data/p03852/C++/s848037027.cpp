#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#define _USE_MATH_DEFINENS
#include <cmath>
using namespace std;

#define MOD 1000000007
#define p(x) cout << x << endl;
#define el cout << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c;
    cin >> c;
    string vowel = "vowel", consonant = "consonant";

    if(c == 'a' or c == 'i' or c == 'u' or c == 'e' or c == 'o'){
        p(vowel);
    }else{
        p(consonant);
    }
}
