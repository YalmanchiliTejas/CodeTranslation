#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll mx[n][n];
    ll mn[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(i==0){
                mx[j][j+i]=a[j];
                mn[j][j+i]=-a[j];
            }
            else{
                ll t1 = mn[j+1][j+i]+a[j];
                ll t2 = mn[j][j+i-1]+a[j+i];
                ll t3 = mx[j+1][j+i]-a[j];
                ll t4 = mx[j][j+i-1]-a[j+i];
                mx[j][j+i] = t1>t2?t1:t2;
                mn[j][j+i] = t3<t4?t3:t4;
            }
            //cout<<mn[j][j+i]<<" "<<mx[j][i+j]<<"  ";
        }
        //cout<<endl;
    }
    cout<<mx[0][n-1]<<endl;
    return 0;
}
