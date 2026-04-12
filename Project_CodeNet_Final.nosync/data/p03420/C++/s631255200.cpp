#include <iostream>
using namespace std;
int main(void){
    long long n,k;
    cin>>n>>k;
    long long ans=0;
    if(k==0){cout<<n*n<<endl;return 0;}
    for(int i=1;i<=n;i++){
        ans+=max(0LL,(i-k)*(n/i));
        ans+=max(0LL,n%i-k+1);
    }
    cout<<ans<<endl;
}
