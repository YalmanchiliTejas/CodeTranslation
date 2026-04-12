#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++ )
#define repf(i,m,n) for(int (i)=m;(i)<n;(i)++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define vec(num,init,name) vector<int> name((num),(init));

int main(){
    int a,b,c,x,y;
    int ans=0;
    cin>>a>>b>>c>>x>>y;
    if(a+b<=c*2){
        cout<<x*a+y*b<<endl;
        return 0;
    }else if(x<=y){
        ans+=x*2*c;
        ans+=(min((y-x)*b,(y-x)*2*c));
    }else{
        ans+=y*2*c;
        ans+=(min((x-y)*a,(x-y)*2*c));
    }
    cout<<ans<<endl;
    return 0;

}