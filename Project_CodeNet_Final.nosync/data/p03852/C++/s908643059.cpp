#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main()
{
    FAST;
    char ch;
    cin>>ch;
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    {
        cout<<"vowel"<<endl;
    }
    else
    {
        cout<<"consonant"<<endl;
    }
    return 0;
}