#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];
struct node{
	vector<int>v;
};
node an,bn;
int res[200005];
int r=0;
void solve(int n){
	
	if(n&1){
		for(int i=n;i>=1;i-=2){
			res[++r]=i;
		}
		for(int i=2;i<=n-1;i+=2){
			res[++r]=i;
		}
	}
	else{
		for(int i=n;i>=2;i-=2){
			res[++r]=i;
		}
		for(int i=1;i<=n-1;i+=2){
			res[++r]=i;
		}
	}
	
}
int main(){
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	}
	if(n==1){
		printf("%d ",a[1]);
	
		return 0;
	}
	solve(n);
	for(int i=1;i<=r;i++){
		cout<<a[res[i]]<<" ";
	}
//		an.v.push_back(1);
//		bn.v.insert(bn.v.begin(),1);
		
//	for(int i=2;i<=n;i++){
//if(i&1){
//     an.v.push_back(i);
//	 bn.v.insert(bn.v.begin(),i);
//}
//else{
//	  bn.v.push_back(i);
//	  an.v.insert(an.v.begin(),i);
//	
//}
//if(i==n){
//	if(n&1){
//		int t=bn.v.size()-1;
//		for(int x=0;x<=t;x++){
//			printf("%d ",a[bn.v[x]]);
//			
//		}
//	}
//	else{
//			int t=an.v.size()-1;
//		for(int x=0;x<=t;x++){
//			printf("%d ",a[an.v[x]]);
//			
//		}
//	}
//}
//		}
	
	

	
	return 0;
}