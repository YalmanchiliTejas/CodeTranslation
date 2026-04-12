#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i= 0; i< s.length();i++)
    {
        if(s[i] == 'A' && s[i+1] == 'C') 
         {
            cout << "Yes" << endl;
            break;
         }
        else if (i==s.length()-1) cout << "No" << endl;
    }

    
    return 0;
}