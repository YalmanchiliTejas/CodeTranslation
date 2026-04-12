#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define boost ios::sync_with_stdio(0); cin.tie(0);
#define int long long

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int32_t main(){
    boost;
    
    //code
    char n;
    cin >> n;

    cout << ((n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u') ? "vowel" : "consonant");
    return 0;
}