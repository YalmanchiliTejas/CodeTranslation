#include <iostream>
using namespace std;
int main(void){
    int n,ans,m;
    int x[100];
    cin>>n;
    cin>>m;
    ans=1;
    for (int i=1;i<n;i++){
        cin>>x[i];
        if(x[i]>=m){
            m=x[i];
            ans++;
        }
    }
    cout<<ans;
}