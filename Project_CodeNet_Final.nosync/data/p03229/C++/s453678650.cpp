#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
#define int long long
signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans = 0;
    //偶数の時 
    if(n%2 ==0){
        for(int i=0;i<n/2;i++){
            if(i == n/2-1) ans -=a[i];
            else ans -= a[i]*2;
        }
        for(int i=n-1; i>=n/2; i--){
            if(i==n/2) ans += a[i];
            else ans += a[i]*2;
        }
        cout<<ans<<endl; return 0;
    }else{//奇数の時
        int ans1 = 0, ans2 = 0;
        int mid = n/2;
        //大から
        for(int i=0;i<n;i++){
            //cout<<a[i]<<'*'<<endl;
            if(mid > i) ans1 -= a[i]*2;
            else if(i == mid|| i == mid+1) ans1 += a[i];
            else ans1 += a[i]*2;
        }
        //cout<<ans1<<endl;
        //小から
        for(int i=0;i<n;i++){
            if(i==mid||mid-1==i) ans2-=a[i];
            else if(i<mid-1) ans2 -= a[i]*2;
            else ans2 += a[i]*2;
        } 
        cout<<max(ans1, ans2)<<endl;
    }
   
}
