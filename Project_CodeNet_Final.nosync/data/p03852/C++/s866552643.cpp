#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    char c;cin>>c;
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        cout<<"vowel"<<endl;
        break;
    default:
        cout<<"consonant"<<endl;
    }
}