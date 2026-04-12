#include <bits/stdc++.h>
using namespace std;
int main(){
    char a;
    string v = "vowel";
    string c = "consonant";
    cin >> a;
    if(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o'){
        cout << v << endl;
        return 0;
    }else {
        cout << c << endl;
        return 0;
    }

}