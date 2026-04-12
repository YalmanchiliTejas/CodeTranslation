#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long int first;
    long long int second;
};
node mat[3002][3002];
int main()
{
    long long int n,i,j,val[100005],len;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    for(i=1;i<=n;i++)
    {
        mat[i][i].first = val[i];
        mat[i][i].second = 0;
    }
    for(len = 2;len<=n;len++)
    {
        for(i=1;i<=n-len+1;i++)
        {
            j = i+len-1;
            if(val[i] + mat[i+1][j].second > val[j] + mat[i][j-1].second)
            {
                mat[i][j].first = val[i] + mat[i+1][j].second;
                mat[i][j].second = mat[i+1][j].first;
            }
            else
            {
                mat[i][j].first = val[j] + mat[i][j-1].second;
                mat[i][j].second = mat[i][j-1].first;
            }
            
        }
    }
    // cout<<"-----------\n";
    // for(i=1;i<=n;i++)
    // {
    //     for(j=1;j<=n;j++)
    //     {
    //         cout<<mat[i][j].first<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"-----------\n";
    // for(i=1;i<=n;i++)
    // {
    //     for(j=1;j<=n;j++)
    //     {
    //         cout<<mat[i][j].second<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<mat[1][n].first - mat[1][n].second<<endl;
}