#include <iostream>
using namespace std;
int main(void){
    long long N,i,H,M,ans;
    cin>>N;
    M=-1;ans=0;
    for(i=0;i<N;i++){
        cin>>H;
        if(H>M-1){
            ans++;
        }
        M=max(M,H);
    }
    cout<<ans<<endl;
}
