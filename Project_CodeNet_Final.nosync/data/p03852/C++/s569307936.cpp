#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < b; ++i)

int main()
{
    char c;
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
        cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}