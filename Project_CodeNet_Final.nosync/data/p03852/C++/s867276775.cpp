#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    char input;
    cin >> input;
    if(input=='a'||input=='i'||input=='u'||input=='e'||input=='o'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
}