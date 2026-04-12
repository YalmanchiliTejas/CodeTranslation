#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string c;
    cin >> c;
    if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u" ){
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant" << endl;
    }
}
