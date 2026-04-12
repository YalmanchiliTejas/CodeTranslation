#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rrep(i,n) for(int (i) = (n) - 1; (i) >= 0; --(i)) //Reversi rep
#define nfor(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) //Natural for
#define rfor(i,a,b) for(int (i) = (b); (i) >= (a); --(i)) //Reversi for

int main()
{
    string c;
    cin >> c;
    if (c[0] =='a'||c[0] =='i'||c[0] =='u'||c[0] =='e'||c[0] =='o') {
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    return 0;
}