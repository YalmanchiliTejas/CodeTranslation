#include<iostream>
using namespace std;
int main()
{   
    string str;
    cin>>str;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='A'&&str[i+1]=='C')
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}