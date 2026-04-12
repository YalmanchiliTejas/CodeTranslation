#include <iostream>
using namespace std;

int main()
{
    char c;
    //cout<<"enter alphabet:";
    cin>>c;
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    cout << "vowel" << endl;
    else
        cout<<"consonant"<<endl;
    return 0;
}