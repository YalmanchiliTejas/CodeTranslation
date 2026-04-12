#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;
const int M=1e9+7;
const int N=200100;
long long a[N],pos[N],n,ans=0;
int main(){
	cin>>n;
	memset(pos,0,sizeof pos);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n-1;i>=1;i--) pos[i]=(pos[i+1]+a[i+1])%M;
	for(int i=1;i<=n-1;i++) ans=((ans%M)+(a[i]*pos[i]%M))%M;
	cout<<ans<<endl;
	return 0;
}