#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <string>
#include <math.h>
using namespace std;

int main(){
    long long int n,k,ans=0;
    cin>>n>>k;
    for(int i=k+1;i<=n;i++){
        ans+=(i-k)*(n/i);
        if((n)%i-k>=0){
            ans+=(n)%i-k+1;
            if(k==0){
                ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
