#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;
long long int gcd(long long int x,long long int  y){
   if(y==0)return x;
   return gcd(y,x%y);
}
int main(){
IOS;
ll n;
cin>>n;
ll arr[n],sum=0,cur=0;
for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
}
for(int i=0;i<n-1;i++){
    sum-=arr[i];
    cur+=(arr[i]%1000000007)*(sum%1000000007);
    cur%=1000000007;
}
cout<<cur;
return 0;
}
/*sjleepy*/