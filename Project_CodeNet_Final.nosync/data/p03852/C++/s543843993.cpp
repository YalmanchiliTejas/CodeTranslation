#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    char c;
    cin>>c;
    string s="aeiou";
    for(int i=0; i<5; i++){
        if(s[i]==c){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}
