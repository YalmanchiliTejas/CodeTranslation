#include <iostream>
using namespace std;

int main()
{
    string s;
    int a,b;
    cin >> a >> s >> b;

    for(int i=0; i<a; i++)
    {
        if(s[i] == s[b-1])
        cout << s[i] ;
        else 
        cout << "*" ;
    }
    cout << endl;

    return 0;
}