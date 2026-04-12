/**
 *      ABC 49 A
 *      author  : kyomukyomupurin
 *      created : 2018-09-20 07:12:59
**/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char c; cin >> c;
    if ((c == 'a' || c == 'e') || ((c == 'i' || c == 'o') || c == 'u')){
        cout << "vowel" << endl; return 0;
    }
    cout << "consonant" << endl;
    return 0;
}