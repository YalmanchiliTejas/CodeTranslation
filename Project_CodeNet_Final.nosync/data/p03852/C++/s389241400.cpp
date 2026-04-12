#include <iostream>
using namespace std;
int i;
char c,v[]="aeiou";
int main()
{
    cin>>c;
    for(i=0;i<5;++i)
        if(v[i]==c)
    {
        cout<<"vowel";
        return 0;
    }
    cout<<"consonant";
    return 0;
}
