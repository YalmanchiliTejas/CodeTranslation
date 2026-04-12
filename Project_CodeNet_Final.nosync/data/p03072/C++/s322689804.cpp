#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    int a[n],cc,ans=1;
    cin>>a[0];
    cc=a[0];

    for(int i=1;i<n;++i){
        cin>>a[i];
        if(a[i]>=cc)ans+=1;
        cc=max(cc,a[i]);
    }
    cout<<ans<<endl;
	return 0;
}