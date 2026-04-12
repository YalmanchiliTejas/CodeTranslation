#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int sum=0;
    if(a>2*c && b>2*c) sum+=max(x,y)*c*2;
    else if((a+b)/2>=c){
        sum+=min(x,y)*c*2;
        int d=2*c;
        if(x>y) sum+=(x-y)*min(a,d);
        else if(x<y) sum+=(y-x)*min(b,d);
    }
    else{
        sum+=a*x+b*y;
    }
    cout<<sum<<"\n";
    return 0;
}