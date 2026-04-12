#include<iostream>
#include<string>
using namespace std;
int main()
{
    string x;
    cin>>x;
    for(int i=0;i<x.size();++i)
    if(x[i]=='a'||x[i]=='e'||x[i]=='i'||x[i]=='o'||x[i]=='u')
       cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
}