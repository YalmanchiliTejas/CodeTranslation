#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    
    ll n;
    cin>>n;
    ll i,j,x[n][n],y[n][n];
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=n-1;i>=0;i--){
        for(j=i;j<n;j++){
            if(i==j){
                x[i][j]=a[i];
                y[i][j]=0;
            }
            else if(j==i+1){
                x[i][j]=max(a[i],a[j]);
                y[i][j]=min(a[i],a[j]);
            }
            else{
                x[i][j]=max(a[i]+y[i+1][j], a[j]+y[i][j-1]);
                if((a[i]+y[i+1][j])== (a[j]+y[i][j-1]))
                y[i][j]=min(x[i][j-1],x[i+1][j]);
                else if(x[i][j]==a[i]+y[i+1][j])
                y[i][j]=x[i+1][j];
                else
                y[i][j]=x[i][j-1];
            }
        }
    }
    cout<<x[0][n-1]-y[0][n-1]<<endl;
}