#include <iostream>

using namespace std;

int main()
{
    char x;
    cin >> x ;
    if (x=='a'||x=='e'||x=='o'||x=='i'||x=='u'||x=='A'||x=='E'||x=='O'||x=='U'||x=='I'){
        cout<<" vowel"<<endl;
    }else{
    cout<<"consonant"<<endl;
    }
       return 0;
}
