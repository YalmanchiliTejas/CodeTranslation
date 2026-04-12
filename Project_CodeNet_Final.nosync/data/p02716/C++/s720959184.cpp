#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int32_t main(){
    if(fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin),
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    	cin >> a[i];
    int x[n],y[n];
    x[0]=0,y[0]=a[0];
    x[1]=max(a[0],a[1]);
    for(int i=2;i<n;i++){
        if(i%2)
            x[i]=a[i]+max(x[i-2],y[i-3]);
        else{
            x[i]=a[i]+x[i-2];
            if(i>=4){
                x[i]=max(x[i],a[i]+y[i-4]);
                x[i]=max(x[i],a[i]+x[i-3]);
            }
            y[i]=a[i]+y[i-2];
        }
    }
    if(n%2)cout << max(x[n-1],x[n-2]);
    else cout << max(x[n-1],y[n-2]);
}