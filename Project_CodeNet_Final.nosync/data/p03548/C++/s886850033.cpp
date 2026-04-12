#include<bits/stdc++.h>
using namespace std;
#define ms(a,b) memset(a,0,sizeof(a))
#define debug(x) cerr<<#x<<"="<<x<<endl;
typedef long long ll;
const int maxn=1e5+100;

int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	int i;
	for(i=1;i<=x;i++){
		if (x>=(i*y+(i+1)*z)){
			continue;
		}
		else{
			i--;
			break;
		}
	}
	cout<<i<<endl;
	return 0;
}