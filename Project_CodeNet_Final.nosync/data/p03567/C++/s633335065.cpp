/*input
ABCD
*/
#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long a[1000005],n;

int main(){
	#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#endif
	long long q,m,k,h,ans=0,sum=0,p,x,y;
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;++i){
		if(s[i]=='A' && s[i+1]=='C')
			return cout<<"Yes",0;
	}
	cout<<"No";
}