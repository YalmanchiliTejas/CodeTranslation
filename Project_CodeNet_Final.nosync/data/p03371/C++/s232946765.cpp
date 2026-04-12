#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    int a,b,c,x,y;
    int xymax=pow(10,5);
    cin >>a>>b>>c>>x>>y;
    c=c*2;
    int ans =2*xymax*5000;
    for(int i=0;i<xymax+1;i++){
        ans=min(ans,i*c+max(0,x-i)*a+max(0,y-i)*b);
    }
    cout << ans << endl;
}
