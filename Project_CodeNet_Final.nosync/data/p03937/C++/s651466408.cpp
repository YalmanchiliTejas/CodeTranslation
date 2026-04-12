#include<iostream>
using namespace std;

char arr[100][100];

int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='#')
                cnt++;
        }
    }

    if(arr[0][0]!='#'||arr[n-1][m-1]!='#')
        cout<<5/0;

    if(cnt!=n+m-1)
        {
            cout<<"Impossible";
            return 0;
        }

    int i=0,j=0;
    int flag=0;
    while(i<n&&j<m)
    {
        if(i==n-1&&j==m-1)
            {
                flag=1;
                break;
            }
        if(j+1<m&&arr[i][j+1]=='#')
        {
            j++;
            continue;
        }
        if(i+1<n&&arr[i+1][j]=='#')
        {
            i++;
            continue;
        }
        break;
    }
    if(flag==1)
        cout<<"Possible";
    else
        cout<<"Impossible";

    return 0;
}
