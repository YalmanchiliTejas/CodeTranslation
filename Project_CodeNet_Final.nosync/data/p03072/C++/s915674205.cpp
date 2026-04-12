#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int h[105];
int main(void){
    int n,h,h2,ans=1;cin>>n>>h;
    for(int i=1;i<n;i++){
        cin>>h2;
        if(h2>=h)ans++;
        h=max(h,h2);
    }
    cout<<ans<<endl;
    
    return 0;
}
