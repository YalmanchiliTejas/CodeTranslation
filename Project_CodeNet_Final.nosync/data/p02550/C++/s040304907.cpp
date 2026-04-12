#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,x,m,ans=0,f=0,b=0,c=0,d=0,t=0;
    cin>>n>>x>>m;
    t=x;
    vector<long long int>a(1000000);
    for(long long int i=0;i<m;i++){
        if(a[x]==0){
            a[x]++;
            x=(x*x)%m;
        }
        else{
            d=i;
            break;
        }
        
    }
    for(long long int i=0;i<m;i++){
        if(t==x&&f==0){
            c=i;
            f=1;
            b+=t;
            t=(t*t)%m;
        }
        else if(f==0){
            ans+=t;
            t=(t*t)%m;
        }
        else if(f==1&&t==x){
            break;
        }
        else{
            b+=t;
            t=(t*t)%m;
        }
    }
    if(a[0]==0){
        ans+=((n-c)/(d-c))*b;
        for(long long int i=0; i<(n-c)%(d-c);i++ ){
            ans+=t;
            t=(t*t)%m;
        }
    }
    cout<<ans<<endl;
    return 0;
}
