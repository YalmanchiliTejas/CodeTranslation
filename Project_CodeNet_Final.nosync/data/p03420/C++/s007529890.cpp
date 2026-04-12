#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<ctime>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<iomanip>
#include<utility>
#include<cctype>
#include<bitset>
#include<list>
using namespace std;

long long ans;
int n,k;

int main(){
	cin>>n>>k;
	if(k==0){
		cout<<(long long)n*n<<endl;
		return 0;
	}
	for(int i=k+1;i<=n;i++){
		ans+=n/i*(i-k)+max(0,n%i-k+1);
	//	cout<<n/i*(i-k)<<" "<<max(0,n%i-k+1)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}