#include<iostream>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
 
using namespace std;
 
int main(){
    ll n,a,sum=0,mini=99999;
    cin>>n;
    lol(i,n){
    cin>>a;
    sum+=a;
    mini=min(mini,sum/(i+1));
    }
    cout<<mini<<endl;
    return 0;
}
