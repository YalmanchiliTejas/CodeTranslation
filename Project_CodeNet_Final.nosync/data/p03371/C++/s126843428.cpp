#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans=0;
    ans+=min(x,y)*min(a+b,2*c);
    int n=abs(x-y);
    ans+=min(n*(x<y?b:a),2*n*c);
    cout<<ans<<endl;
    return 0;
}