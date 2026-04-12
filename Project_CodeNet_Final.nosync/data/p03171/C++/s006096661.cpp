#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n];
    ll mat[n][n];
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
mat[i][j]=0;
    for(int i=0;i<n;i++){

    cin>>a[i];
    mat[i][i]=a[i];}
    for(int l=2;l<=n;l++){
    for(int i=0;(i+l)<=n;i++){
mat[i][i+l-1]=max(a[i]-mat[i+1][i+l-1],a[i+l-1]-mat[i][i+l-2]);
    }
    }

    cout<<mat[0][n-1];






    return 0;}
