#include <iostream>
using namespace std;
int n,a,b,ans;
int main(void){
    cin>>n>>a;
    for(int i=1;i<n;i++){
        cin>>b;
        if(a<=b){ans++;a=b;}
    }
    cout<<ans+1<<endl;
}
