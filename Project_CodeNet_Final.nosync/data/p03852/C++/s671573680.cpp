#include <iostream>

using namespace std;

int main()
{
    char letter, arr[]="aeiou";
    cin>>letter;
    for(int i=0; i<6; i++)
    {
        if (arr[i]==letter)
        {
            cout<<"vowel";
            return 0;
        }
    }
    cout<<"consonant";
}
