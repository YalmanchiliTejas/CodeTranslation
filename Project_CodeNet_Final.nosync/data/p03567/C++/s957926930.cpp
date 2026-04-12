#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'&&s[i+1]=='C')
            k=1;
    }
    if(k==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
