#include <iostream>
#define INF (2<<29)
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    for(;;){
        int a,n,s=0,max=0,min=INF;
        cin>>n;
        if(n==0) break;
        for(int i = 0; i < n; i++){
            cin>>a;
            s+=a;
            if(max<a) max=a;
            if(min>a) min=a;
        }
        cout<<(s-max-min)/(n-2)<<endl;
    }
    return 0;
}