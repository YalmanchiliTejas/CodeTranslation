#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;

typedef unsigned long long ll;

const long long MOD = 1000000000 + 7;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    string c;
    cin >> c;
    if(c ==  "a" || c ==  "i" || c ==  "u" ||c ==  "e" || c ==  "o" ) {
        cout << "vowel" << endl;
        return 0;
    }else{
        cout << "consonant" << endl;
        return 0;
    }
    return 0;
}
