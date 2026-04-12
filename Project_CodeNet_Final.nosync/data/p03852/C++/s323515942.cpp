#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    char s;
    cin >> s;

    if(s == 'a'||s=='i'||s=='o'||s=='u'||s=='e'){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}
