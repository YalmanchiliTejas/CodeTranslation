#include<iostream>

using namespace std;

int main( void ){
    std::string s;
    cin >> s;
    bool busNeeds = false;
    for( int i = 1; i < 3; i++ ){
         if( s[i-1] != s[i] ){
             busNeeds = true;
             break;
         }
    }
    if( busNeeds ) cout << "Yes" << endl;
    else           cout << "No" << endl;
return 0;
}
