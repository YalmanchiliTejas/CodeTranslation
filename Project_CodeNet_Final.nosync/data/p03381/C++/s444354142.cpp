#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) rep2(i,0,n)

using namespace std;


main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    rep(i,n) cin>>a[i];
    rep(i,n) b[i]=a[i];
    sort(a,a+n);
    int min=a[n/2-1]; int max=a[n/2];
    rep(i,n){
        if(b[i]<=min) cout<<max;
    else cout<<min;
      cout<<endl;
    }
    return 0;
}