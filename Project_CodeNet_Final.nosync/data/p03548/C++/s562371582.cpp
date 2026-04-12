#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=1;
    while(1){
        if(a>=(ans+1)*c+ans*b){
            ans++;
        }else{
            break;
        }
    }
    cout<<ans-1<<endl;
    return 0;
}