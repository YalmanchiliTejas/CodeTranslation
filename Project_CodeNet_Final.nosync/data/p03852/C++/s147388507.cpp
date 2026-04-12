#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

int main(){
    char str;
    cin >> str;
    if(str == 'a' ||str == 'i' ||str == 'u' ||str == 'e' ||str == 'o' )
        cout << "vowel" << endl;
    else 
        cout << "consonant" << endl;

    return 0;
}