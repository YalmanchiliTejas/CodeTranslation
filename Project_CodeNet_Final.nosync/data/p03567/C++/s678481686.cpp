#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int f=0;
     string s;
     cin>>s;
     for(int i=0;i<s.size();i++)
     {
       if(s[i]=='A'&&s[i+1]=='C')
       {f=1;break;}
       else
       {f=0;}

     }
     if(f)
        printf("Yes\n");
     else
        printf("No\n");
}
