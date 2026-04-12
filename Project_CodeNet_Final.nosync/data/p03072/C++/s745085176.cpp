#include<bits/stdc++.h>

#define f(z) for(int i=1;i<=z;i++)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    fast
     int n , mx, kt=1;
     cin>>n;
     int a[n+1];
     f(n) cin>>a[i];
      mx=a[1];
     for(int i=2 ; i<=n ; i++){
        if(mx<= a[i]){

            ++kt;
            mx=a[i];
        }
     }

     cout<<kt<<endl;
}
