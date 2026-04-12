#include<iostream>
using namespace std ;
int main()
{
    string s ;
    cin >> s ;
    int f=0;
    for(int i=0;i<2;i++)
    {
        if(s[i]!=s[i+1]){f=1;}
    }
    if(f==1)
    {
        cout << "Yes" << endl;
    }
    else{cout << "No" << endl;}
    return 0 ;
}
