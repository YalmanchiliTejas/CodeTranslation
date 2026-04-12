#include <iostream>

using namespace std;


int main()
{
    char letterts[5] = {'a' , 'e' , 'i' , 'o' , 'u'};
    char input;
    cin>>input;
    for(int i=0 ; i<5 ; i++)
    {
        if(input==letterts[i])
        {
            cout<<"vowel\n";
            break;
        }
        else if(input!=letterts[i]&&i==4)
        {
            cout<<"consonant\n";
        }
    }
    return 0;
}
