#include <bits/stdc++.h>
using namespace std;
#define N_PRIME 1000000007
#define ll int64_t


int main(void){
    string s;
    cin >> s;
    if( s[0] == 'a' || s[0] == 'i' || s[0] == 'u' || s[0] == 'o' || s[0] == 'e' ){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    
    return 0;
}