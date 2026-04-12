#include <iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++)cin>>h[i];
    
    int ans=1;
    int max=h[0];
    for(int i=1;i<n;i++){
        if(max<=h[i]){
            max=h[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}
