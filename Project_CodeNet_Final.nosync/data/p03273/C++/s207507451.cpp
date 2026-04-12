#include <iostream>;
using namespace std;
int main ()
{
    int n,m;
    cin>>n>>m;
    char q[n][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>q[i][j];
        }
    }
    int line[n]={0},column[m]={0},x=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (q[i][j]=='.'){x++;}
        }
        if (x==m){line[i]++;}
        x=0;
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (q[j][i]=='.'){x++;}
        }
        if (x==n){column[i]++;}
        x=0;
    }
    //for (int i=0;i<n;i++){cout<<line[i]<<" ";}
    //cout<<endl;
    //for (int i=0;i<m;i++){cout<<column[i]<<" ";}
    for (int i=0;i<n;i++)
    {
        if (line[i]==1){continue;}
        for (int j=0;j<m;j++)
        {
            if (column[j]==1){continue;}
            cout<<q[i][j];
        }
        cout<<endl;
    }
    return 0;
}