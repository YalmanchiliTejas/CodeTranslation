#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll d[n][n];
    int i,j;
    for(i=0,j=0;i<n;i++,j++)
        d[i][j]=a[i];
        for(int k=1;k<n;k++){
            for(i=0,j=k;j<n;i++,j++){
                d[i][j]=max(a[i]-d[i+1][j], a[j]-d[i][j-1]);
            }
        }
    cout<<d[0][n-1]<<endl;
}