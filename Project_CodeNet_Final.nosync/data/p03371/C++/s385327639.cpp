    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <vector>
    #include <cmath>
    #include <map>

    #define ll long long
    #define mod 1000000007
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

       ll a,b,c,x,y;
       cin>>a>>b>>c>>x>>y;
       ll temp1=a*x + b*y;
       ll temp2=max(x,y)*2*c;
       ll temp3,temp4;
       if(x<y) {
           temp3=x*2*c;
           y-=x;
           temp3+=min(y*b,y*2*c);
       } else {
           temp3=y*2*c;
           x-=y;
           temp3+=min(x*a,x*2*c);
       }
        ll ans=min(temp1,min(temp2,temp3));
       cout<<ans<<"\n";
        return 0;
    }