#include <iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>

using namespace std;
int main()
{
    char arr[]={'a','e','o','u','i'};
    char v;
    cin>>v;
    bool flag=false;
    for(int i=0 ;i<strlen(arr);i++)
    {
        if(arr[i]==v){cout<<"vowel";flag=true;};
    }
    if(flag==false)
        cout<<"consonant";
}