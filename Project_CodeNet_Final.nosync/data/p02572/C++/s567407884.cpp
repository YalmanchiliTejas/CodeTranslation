#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define MAX 100
#define THOU 1000
#define FIVEMAX 100000
#define NINEMAX 1000000000
#define TWEMAX 1000000000000
#define rep(i,n) for (int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;i>=0;i--)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define darep(i,a,n) for(int i=n,i>=a;i--)
 
int main(){
 cin.tie(0);
 ios::sync_with_stdio(false);
 
 //ll a[2*FIVEMAX+1];
 //ll s[2*FIVEMAX+1];
 
 int n;
 
 cin>>n;
 vector<ll>a(n);
 vector<ll>s(n+1,0);
 for(int i=0;i<n;i++)cin>>a[i];
 
 for(int i=0;i<n;i++){
     s[i+1]=s[i]+a[i];
 }
 
ll nine=NINEMAX+7;
ll amari=0;
for(int i=0;i<n;i++){
    ll b = (s[n]-s[i+1])%nine;
    amari+=b*(a[i]%nine)%nine;
    amari=amari%nine;
}

cout<<amari<<endl;
return 0;
}