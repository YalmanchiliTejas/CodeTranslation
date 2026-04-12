#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb1(x) cout<<#x<<" :: "<<x<<"\n";
#define deb2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define deb3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define lli long long int
#define pii pair<lli,lli>
#define f first
#define sE second
lli n,x,y,t,mod=1e9+7,ans=0; 
int main() { 
    fast
    string s;
    cin>>s;
    if(s[0]!=s[1] || s[1]!=s[2] || s[0]!=s[2])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
} 