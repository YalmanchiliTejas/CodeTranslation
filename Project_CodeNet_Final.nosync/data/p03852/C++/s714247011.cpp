#include<iostream>
#include <string>
using namespace std;
int main()
{
    char a;
    char v[5]={'a','o','i','e','u'};
    cin>>a;
    bool f=false;
    for(int i=0;i<5;i++){
    if(a==v[i]){
    f=true;
    break;
    }
    }
    if(f==true)cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
return 0;
}