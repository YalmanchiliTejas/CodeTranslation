#include<bits/stdc++.h>

#define pb push_back
#define f first
#define s second
using namespace std;


int main()
{
    char s[3];
    int k=0;
    for(int i=0;i<3;i++)
       { cin>>s[i];if(s[i]=='A')k++;
       }
    if(k==0||k==3)cout<<"No";
    else cout<<"Yes";
return 0;
}

