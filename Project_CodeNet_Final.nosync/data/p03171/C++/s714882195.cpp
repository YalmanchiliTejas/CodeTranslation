#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n][n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i][i];
    }
    for(long long int i=2;i<=n;i++){
        for(long long int j=0;i+j<=n;j++){
            arr[j][i+j-1]=max(arr[j][j]-arr[j+1][i+j-1],arr[i+j-1][i+j-1]-arr[j][i+j-2]);
        }
    }
    cout<<arr[0][n-1]<<"\n";;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
