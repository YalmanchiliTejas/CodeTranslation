#include<iostream>
#include<string>
using namespace std;
bool isleft(char a)
{
    return(
         a=='q'|| a=='w'|| a=='e'|| a=='r'|| a=='t'||
         a=='a'|| a=='s'|| a=='d'|| a=='f'|| a=='g'||
         a=='z'|| a=='x'|| a=='c'|| a=='v'|| a=='b');
}


int main()
{
    string s;
    while(cin >>s &&s!="#")
    {
        int j=0;
        for(int i=0;i<s.size()-1;i++)
        { j+= isleft(s[i]) ^ isleft(s[i+1]);}
        cout << j << endl;


    }
    return 0;
}