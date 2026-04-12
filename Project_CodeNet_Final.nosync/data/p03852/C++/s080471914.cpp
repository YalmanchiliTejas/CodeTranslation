#include <iostream>

using namespace std;

int main()
{
    char k;
    cin>>k;
    if(k == 'a' || k == 'e' || k == 'i' || k == 'o'|| k == 'u')
    {
        cout<<"vowel"<<endl;
    }
    else
    {
        cout<<"consonant"<<endl;
    }
    return 0;
}
