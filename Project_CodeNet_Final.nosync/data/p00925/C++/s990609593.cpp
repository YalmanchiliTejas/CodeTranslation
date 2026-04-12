#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include <deque>
#include <list>
#include <ctime>
#include <stack>
#include <vector>
#include<set>
#define MAX 1005
typedef long long ll;
const int inf = 0x3f3f3f3f;
using namespace std;

char s[22];
stack<int> a ;

int main()
{
    while(~scanf("%s",s))
    {
        int num ;
        scanf("%d",&num);
        int len=strlen(s);
        int l=s[0]-'0';
        for(int i=1;i<len;i++)
        {
            if(i%2==1)
            {
                if(s[i]=='+')
                    l=l+s[i+1]-'0';
                else
                    l=l*(s[i+1]-'0');
            }
        }
        while(!a.empty()) a.pop();
        int m=1;
        for(int i=0;i<len;i++)
        {
            if(i%2==1)
            {
                if(s[i]=='*')
                {
                   // cout<<m<<endl ;
                    m=a.top();
                    m=m*(s[i+1]-'0');
                    a.pop();
                    a.push(m);
                    i++;
                }
            }
            else
            {
               // cout<<s[i]-'0'<<endl;
                a.push(s[i]-'0');
            }
        }
        m=0;
        while(!a.empty())
        {
            m+=a.top();
            a.pop();
        }
        //cout<<m<<"  "<<l<<endl ;
        if(num==l&&num!=m) printf("L\n");
        else if(num==m&&num!=l)  printf("M\n");
        else if(num==m&&num==l)  printf("U\n");
        else printf("I\n");
    }
    return 0 ;
}