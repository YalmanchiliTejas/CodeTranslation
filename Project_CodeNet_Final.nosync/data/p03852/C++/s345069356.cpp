#include<iostream>
#include<cstdio>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    string m ="aiueo";
    string ans = "consonant";
    for(int i=0; i<5; i++){
        if(s[0]==m[i]){
            ans ="vowel";
        }
    }
    cout << ans << endl;
    return 0;
}