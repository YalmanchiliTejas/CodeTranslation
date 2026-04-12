#include<bits/stdc++.h>//偷懒专用库 
#define MAXN 99999
#define INF 101//两个宏定义 
using namespace std;
inline int read(){
 char c=getchar();int x=0,f=1;
 while(c>'9'||c<'0'){if(c!='-')f=-1;c=getchar();}
 while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
 return x*f;
}//快读，想学习的可以借鉴 
char s[INF][INF];//用来存字符 
int n,m,tot,pop;//n代表行，m代表列，tot和pop用来判断 
int main()
{
    n=read();
    m=read();//读入行和列 
    for(int i=1;i<=n;++i)
     for(int j=1;j<=m;++j)
      cin>>s[i][j];//读入字符 
    s[0][1]=s[1][0]='#';//很关键，如果不写，输出结果全部都是Impossible 
    for(int i=1;i<=n;++i)
     for(int j=1;j<=m;++j)
      {
        tot=0;
        pop=0;//初始化 
        if(s[i][j]=='#')
         {
            if(s[i][j+1]=='#')
             tot++;
            if(s[i+1][j]=='#')
             tot++;//判断下面和右面有一个还是两个，按照题意，两个位置只能存在一个 
            if(s[i-1][j]!='#')
             pop++;
            if(s[i][j-1]!='#')
             pop++;//这个是判断上面或者左边有没有，也就是确定有没有方法能到达 
         }
        if(tot==2||pop==2)
         {
            cout<<"Impossible\n";
            return 0;//只要不满足其中一种，就输出不可能，然后直接结束 
         }
      }
    cout<<"Possible\n";//否则输出可能 
    return 0;//别忘了打return 0 
}