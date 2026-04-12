#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

#define INF -10000000000000

int main(){
    ll d[3][200000];
    ll a[200000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        d[0][i]=d[1][i]=d[2][i]=INF;
        cin>>a[i];
    }
    d[0][0]=0;
    d[1][1]=0;
    d[2][2]=0;
    for(int i=2;i==2;i++){
        d[0][i]=d[0][i-2]+a[i-2];
    }
    for(int i=3;i==3;i++){
        d[0][i]=d[0][i-2]+a[i-2];
        d[1][i]=max(d[1][i-2]+a[i-2],d[0][i-3]+a[i-3]);
    }
    for(int i=4;i<n;i++){
        d[0][i]=d[0][i-2]+a[i-2];
        d[1][i]=max(d[1][i-2]+a[i-2],d[0][i-3]+a[i-3]);
        d[2][i]=max(d[2][i-2]+a[i-2],max(d[1][i-3]+a[i-3],d[0][i-4]+a[i-4]));
        //cout<<i<<":"<<d[0][i]<<":"<<d[1][i]<<":"<<d[2][i]<<endl;
    }
    ll sum=0;
    if((n+1)%2){
        sum=max(d[0][n-2]+a[n-2],d[1][n-1]+a[n-1]);
    }else{
        sum=max(d[0][n-3]+a[n-3],max(d[1][n-2]+a[n-2],d[2][n-1]+a[n-1]));
    }
    cout<<sum;

    return 0;
}