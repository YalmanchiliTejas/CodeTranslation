#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define boost ios::sync_with_stdio(0); cin.tie(0);
#define int long long

const int N = 100 + 10;
const int MOD = 1e9 + 7;

int32_t main(){
    boost;
    //code
    
    char c;
    cin >> c;
    cout <<  ( ( c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' ) ? "vowel" : "consonant"); 
    return 0;
}