#include<iostream>
#include<assert.h>
#include<vector>

#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define write freopen("in.txt","r",stdin); freopen("out.txt","w",stdout); 

using namespace std;
//assert(x==i);
void solve()
{
int n;
cin>>n;
if(n<30)
	cout<<"No\n";
else
	cout<<"Yes\n";
}
int main() 
{
ios;
//write;
int tc=1;
//cin>>tc;
for(int i=1;i<=tc;i++)
{
//cout<<"Case #"<<i<<": ";
solve();
}
return 0;
}
