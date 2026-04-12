#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans=0;
    int han=min(x,y);
    int nokori=max(x,y)-han;
    if(c>=(a+b)/2.0){
         ans=a*x+b*y;
    }
    else{
        ans+=han*2*c;
        if(x>y && c<=a/2)ans+=c*nokori*2;
        else if(x>y)ans+=a*nokori;
        else if(y>x && c<=b/2) ans+=c*nokori*2;
        else if(y>x) ans+=b*nokori;    
    }

    cout<<ans<<endl;
}
