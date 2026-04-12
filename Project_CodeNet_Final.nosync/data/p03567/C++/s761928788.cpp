#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    char ch[10];
    cin>>ch;
    int flag=0;
    for(int i=0;i<strlen(ch)-1;i++)
    {
        if(ch[i]=='A'&&ch[i+1]=='C')
        {
            flag=1;
            break;
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
