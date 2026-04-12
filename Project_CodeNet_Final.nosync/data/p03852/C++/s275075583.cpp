#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;

int main(){
    string s; cin >> s;
    if(s == "a")print("vowel");
    else if(s == "i")print("vowel");
    else if(s == "u")print("vowel");
    else if(s == "e")print("vowel");
    else if(s == "o")print("vowel");
    else print("consonant");
}