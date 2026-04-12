#include<iostream>

using namespace std;
int main()
{
    string s;
    cin>>s;
    int i=0,s1=0,s2=0;
    while(s[i]!='\0'){
        if(s[i]=='A'){
            s1++;
        }
        if(s[i]=='B'){
            s2++;
        }
        i++;
    }
    if(s1>0 && s2>0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}
