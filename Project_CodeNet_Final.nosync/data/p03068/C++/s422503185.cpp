#include<iostream>
using namespace std;

int main()
{
    string s;
    int n,k,a;
    cin>>n;
    cin>>s;
    cin>>k;

    for(a=0;a<n;a++){
        if(s[k-1]==s[a]){
            cout<<s[a];
        }
        else{
            cout<<"*";
        }

    }

    return 0;

}