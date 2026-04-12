#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[3001][3001]={0};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if( (i+j) >= n){continue;}
            a[i][j]=max(a[0][i+j]-a[i-1][j],a[0][j]-a[i-1][j+1]);
        }
    }
    cout<<a[n-1][0];
    return 0;

}