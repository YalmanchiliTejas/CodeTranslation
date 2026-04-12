#include<iostream>
#include<cstring>
using namespace std;
char str[105][105],row[105],column[105];
int main()
{

    int n,m;
    while(cin>>n>>m)
    {
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        for(int i=0; i<n; i++)
            cin>>str[i];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(str[i][j]=='#')
                    row[i]=1,column[j]=1;
            }
        }
        int flag=0;
        for(int i=0; i<n; i++)
        {
            flag=0;
            for(int j=0; j<m; j++)
            {
                if(row[i]==1&&column[j]==1)
                {
                    cout<<str[i][j];
                    flag=1;
                }
            }
            if(flag==1)
                cout<<endl;
        }
    }
    return 0;
}
