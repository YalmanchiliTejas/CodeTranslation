#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    long long int sum=0;
    if(2*c<a && 2*c<b)sum+=2*c*max(x,y);
    else if(a+b<2*c)sum+=a*x+b*y;
    else{
        sum+=2*c*min(x,y);
        if(x>y)sum+=min(a*(x-y),2*c*(x-y));
        else sum+=min(b*(y-x),2*c*(y-x));
    }
    cout<<sum<<endl;
    return 0;
}