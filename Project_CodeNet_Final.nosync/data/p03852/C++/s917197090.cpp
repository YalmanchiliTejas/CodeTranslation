#include <iostream>
using namespace std;

int main()
{char c;
    cin >> c;
    int code = int(c);
    
    
    if (code == int('a')||code==int('e')||code==int('i')||code==int('o')||code==int('u'))
        cout <<"vowel";
    else
        cout <<"consonant";
        
}