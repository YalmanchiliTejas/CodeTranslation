#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    char c; cin >> c;
    char v[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++){
        if(c == v[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}
