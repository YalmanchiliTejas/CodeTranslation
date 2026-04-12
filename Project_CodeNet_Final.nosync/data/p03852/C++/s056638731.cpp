#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    char a;
    cin >> a;
    
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        cout << "vowel" << endl;
        return 0;
    }
    else
    {
        cout << "consonant" << endl;
        return 0;
    }
    return 0;
}