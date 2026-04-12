#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    int ans1 = a*x+b*y;
    int ans2 = 2*c*max(x,y);
    int ans3 = (x>=y)?(2*c*y+a*(x-y)):(2*c*x+b*(y-x));
    co(min(ans1, min(ans2, ans3)));
}