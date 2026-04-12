#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int n,s,sum=0,i=0;
    int ma=0;
    int mi=10000;
    while(true){
        cin>>n;
        sum=0;
        i=0;
        ma=0;
        mi=10000;
        if(n==0)break;
        //cout<<n<<endl;
        while(i<n){
            cin>>s;
            ma=max(ma,s);
            mi=min(mi,s);
            sum+=s;
            i++;
        }
        sum=sum-ma-mi;
        cout<<sum/(n-2)<<endl;
    }
    return 0;
}
