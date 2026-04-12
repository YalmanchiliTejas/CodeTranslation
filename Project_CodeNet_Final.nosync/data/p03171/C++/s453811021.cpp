#include<bits/stdc++.h> 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    cin>>n;
    vector<long long int> a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<vector<long long int>> x(n+1);
    vector<vector<long long int>> y(n+1);
    int play=0;
    if(n%2==0)
        play=1;

    x[1]=vector<long long int> (n,0);
    y[1]=vector<long long int> (n,0);

    if(play==0)
    {
        for(i=0;i<n;i++)
            x[1][i]=a[i];
    }
    else
    {
        for(i=0;i<n;i++)
            y[1][i]=a[i];
    }
    
    play=(play+1)%2;
    for(i=2;i<=n;i++)
    {
        x[i]=vector<long long int> (n,0);
        y[i]=vector<long long int> (n,0);
        
        for(j=0;j<=n-i;j++)
        {
            if(play==0)
            {
                long long int diff1=a[j]+x[i-1][j+1]-y[i-1][j+1];
                long long int diff2=a[j+i-1]+x[i-1][j]-y[i-1][j];
                if(diff1>diff2)
                {
                    x[i][j]=a[j]+x[i-1][j+1];
                    y[i][j]=y[i-1][j+1];
                }
                else
                {
                    x[i][j]=a[j+i-1]+x[i-1][j];
                    y[i][j]=y[i-1][j];
                }
                
            }
            else
            {
                long long int diff1=x[i-1][j+1]-y[i-1][j+1]-a[j];
                long long int diff2=x[i-1][j]-y[i-1][j]-a[j+i-1];
                if(diff1<diff2)
                {
                    y[i][j]=y[i-1][j+1]+a[j];
                    x[i][j]=x[i-1][j+1];
                }
                else
                {
                    y[i][j]=y[i-1][j]+a[j+i-1];
                    x[i][j]=x[i-1][j];
                }
                
            }
            
        }

        play=(play+1)%2;

    }
    cout<<(x[n][0]-y[n][0])<<endl;

}