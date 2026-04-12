#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int main(){
    string c;cin >> c;

    if (c == "a" || c == "e" || c == "o" || c == "u" || c == "i"){
        cout << "vowel" << endl;
    } else {
        cout << "consonant"<< endl;
    }

	return 0;
}