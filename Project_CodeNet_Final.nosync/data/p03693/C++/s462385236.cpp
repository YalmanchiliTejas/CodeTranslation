#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fr first
#define sc second
const int inf=INT_MAX;
const int nmax=1e5+5;
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int r,g,b,ans;
int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>r>>g>>b;
    ans=r*100+g*10+b;
    if(ans%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}