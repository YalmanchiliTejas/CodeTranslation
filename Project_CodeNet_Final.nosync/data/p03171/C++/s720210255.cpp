#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long int A[n];
    for( int i=0;i<n ;i++) cin>>A[i];
    
	long long int su[n+1];
    su[0]=0;
    for( int i=1;i<=n;i++)
    {
        if(i==1) su[i]=A[i-1];
        else su[i]=su[i-1]+A[i-1];
    }
    
    long long int arr[n][n];
    for( int i=1;i<=n;i++)
    {
        for( int j=0;j<=n-i;j++)
        {
            if(i==1)
            {
                arr[j][j+i-1]=A[j];
            }
            else
            {
                arr[j][j+i-1] = max(su[j+i]-su[j]-arr[j][j+i-2],su[j+i]-su[j]-arr[j+1][j+i-1]);
            }
        }
    }
    
    cout<< (2*arr[0][n-1]) - su[n];
}
