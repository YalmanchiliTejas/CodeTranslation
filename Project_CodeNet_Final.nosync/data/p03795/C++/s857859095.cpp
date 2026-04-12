#include <iostream>
using namespace std;
int main(){
int n,e,s;
long long r;
cin>>n;
if(n>=15){
    if(n%15==0){
        r=(n/15)*200;
        cout<<(n*800)-r<<"\n";
    }
    else{
        s=n%15;
        e=n-s;
        cout<<((e*800)-((n/15)*200))+(s*800)<<"\n";
    }
}
else{
    cout<<n*800;
}


}
