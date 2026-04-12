#include<bits/stdc++.h>
#define MAXN 99999
#define INF 101
using namespace std;
inline int read(){
 char c=getchar();int x=0,f=1;
 while(c>'9'||c<'0'){if(c!='-')f=-1;c=getchar();}
 while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
 return x*f;
}
char s[INF][INF];
int n,m,tot,pop;
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i)
     for(int j=1;j<=m;++j)
      cin>>s[i][j];
    s[0][1]=s[1][0]='#';
    for(int i=1;i<=n;++i)
     for(int j=1;j<=m;++j)
      {
      	tot=0;
      	pop=0;
      	if(s[i][j]=='#')
      	 {
      	 	if(s[i][j+1]=='#')
      	 	 tot++;
      	 	if(s[i+1][j]=='#')
      	 	 tot++;
      	 	if(s[i-1][j]!='#')
      	 	 pop++;
      	 	if(s[i][j-1]!='#')
      	 	 pop++;
         }
        if(tot==2||pop==2)
         {
         	cout<<"Impossible\n";
         	return 0;
         }
      }
    cout<<"Possible\n";
    return 0;
}