#include<bits/stdc++.h>
using namespace std;
#define M 100005
int n,A[M],B[M],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>A[i];
	B[++ans]=A[n];
	for(int i=n-1;i>=1;i--){
		if(B[ans]<=A[i])B[++ans]=A[i];
		else {
			int l=1,r=ans,res;
			while(l<=r){
				int mid=l+r>>1;
				if(B[mid]<=A[i])l=mid+1;
				else r=mid-1,res=mid;
			}
			B[res]=A[i];
		}
	}
	cout<<ans;
	return 0;
}