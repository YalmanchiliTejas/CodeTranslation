#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[100005];
int b[200005];
int le;
int mid;
int main(void){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//priority_queue<int> pque;
	b[100000]=a[0];
	b[99999]=-1;
	le=99998;
	for(int i=0;i<=99998;i++){
		b[i]=1000000007;
	}
	for(int i=1;i<n;i++){
		int l=le; int r=100001;
		while(r-l>1){
			mid=(l+r)/2;
			if(b[mid]>=a[i]){
				r=mid;
			}else{
				l=mid;
			}
		}
		//cout<<l<<endl;//" "<<le<<endl;
		if(l-1==le){
			b[l]=a[i];
			le--;
			b[le+1]=-1;
		}else{
			b[l]=a[i];
		}
		for(int i=le;i<=100000;i++){
			//cout<<b[i]<<" ";
		}
		//cout<<endl;
	}
	//cout<<le<<endl;
	cout<<100000-le-1<<endl;
	
}
