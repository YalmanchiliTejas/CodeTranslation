#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
#define fi first
#define se second

signed main(){
	int n;
	cin>>n;
	int a[n];
	r(i,n)cin>>a[i];

	for(int i=100000;;i--){
		int s=0,f=0;

		r(j,n){
			s+=a[j];
			if(s<i){
				f=1;
				break;
			}
			s-=i;
		}
		if(f)continue;
		cout<<i<<endl;
		break;
	}
}
