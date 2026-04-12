#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

bool check ( char c ) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    char c;
    while( cin >> c ) {
        if( check( c ) ) cout << "vowel\n";
        else cout << "consonant\n";
    }
    return 0;
}
