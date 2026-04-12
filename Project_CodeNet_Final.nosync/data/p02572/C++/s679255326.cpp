#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int ans=0,n,z=0;
    cin>>n;
    vector<long long int>a(300000);
    for(int i=0;i<n;i++){
        cin>>a[i];
        z=(z+a[i])%1000000007;
    }

    for(int i=0;i<n;i++){
        z=((z+1000000007)-a[i]%1000000007)%1000000007;
        ans=(ans+((z)*(a[i])))%1000000007;
    }
    cout<<ans<<endl;

    return 0;
}
