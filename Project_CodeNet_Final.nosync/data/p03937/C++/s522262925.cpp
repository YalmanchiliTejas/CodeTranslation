/*#include "unp.h"
int main()
{
    int listenfd,connfd;
    pid_t childpid;
    socklen_t chilen;
    struct sockaddr_in chiaddr,servaddr;
    listenfd=Socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(SERV_PORT);
    Bind(listenfd,(SA*)&servaddr,sizeof(servaddr));
    Listen(listenfd,LISTENQ);
    for(;;)
    {
        chilen=sizeof(chiaddr);
        connfd=Accept(listenfd,(SA*)&chiaddr,&chilen);
        if((childpid=Fork())==0)
        {
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }
}*/
#include <bits/stdc++.h>
using namespace std;
string str[10];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>str[i];
            for(int j=0; j<m; j++) if(str[i][j]=='#') sum++;
        }
        int x=0,y=0,step=n+m-1;
        int t=1;
        if(sum!=step||str[0][0]!='#'||str[n-1][m-1]!='#')
        {
            puts("Impossible");
            continue;
        }
        while(t<step)
        {
            int l,r;
            l=r=0;
            if(y+1<m&&str[x][y+1]=='#') r=1;
            if(x+1<n&&str[x+1][y]=='#') l=1;
            if(l^r)
            {
                if(r) y+=1;
                else
                    x+=1;
            }
            else break;
            t+=1;
        }
        puts(t==step?"Possible":"Impossible");
    }

    return 0;
}
