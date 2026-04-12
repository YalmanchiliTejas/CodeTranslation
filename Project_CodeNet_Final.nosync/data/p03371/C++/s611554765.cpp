#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
using namespace std;

int main(){
    long long a,b,c,x,y,total=0;
    cin>>a>>b>>c>>x>>y;
    
    if(a+b>=2*c) total += 2*c*min(x,y);
    else total += (a+b)*min(x,y);
    
    if(min(x,y)==x){
        if(b>=2*c) total += 2*c*(y-x);
        else total += b*(y-x);
    }else{
        if(a>=2*c) total += 2*c*(x-y);
        else total += a*(x-y);
    }
    
    cout<<total<<endl;
    return 0;
}