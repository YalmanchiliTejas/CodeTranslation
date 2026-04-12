#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    string s;
    cin >> s;

    string t="aiueo";

    rep(i,5){
        if(s[0]==t[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant" << endl;

    return 0;
}