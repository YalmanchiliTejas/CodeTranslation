#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int r=1e9+7;
int main(){

ll n;
cin>>n;

ll arr[n+1];
ll arr1[n+1];
for(int i=0;i<n;i++){
    cin>>arr[i];

}
int a=0;
ll sum=0;
ll b=0;
for(int i=n-1;i>0;i--){
    b+=arr[i];
    sum+=((b%r)*(arr[i-1])%r)%r;
    sum%=r;
}
cout<<sum%r;
return 0;
}
