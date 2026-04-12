#include<iostream>

using namespace std;

int main(){
        long long n,k;
        cin>>n>>k;
        long long ans = 0;
        for(int i=k+1;i<=n;i++){ //B
                ans += (i-k)*(n/i);
                if(k!=0) ans += max(0LL,(n%i)-k+1);
                else ans += max(0LL,(n%i)-k);
                //cout<<"total:" <<((i-k)*(n/i))<<" tail:"<<max(0LL,(n%i)-k)<<endl;
        }
        cout<<ans<<endl;
        return 0;
}