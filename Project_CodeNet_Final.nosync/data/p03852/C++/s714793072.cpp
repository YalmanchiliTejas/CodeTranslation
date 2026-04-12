// head{{{
/* vim: set foldmethod=marker ft=cpp: */
#include <iostream>
#include <list>
#pragma GCC optimize("O3")
using namespace std;
// }}}
 
int main() {
    //optimize{{{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //---------}}}

    char c;
    cin >> c;
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}

