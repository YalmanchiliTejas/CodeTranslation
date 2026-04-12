#include<bits/stdc++.h>
using namespace std;

unsigned long long solve(){
	unsigned long long n,M,x,y,p,q;
	cin>>n>>x>>M;
	vector<int>A(M);
	p=0;
	unsigned long long sum=x;
	A[x]=1;
	q=x;
	for(unsigned long long i=2;i<=n;i++){
		q=(q*q)%M;	
		if(A[q]){
			p=i;
			break;
		}
		A[q]=i;
		sum=sum+q;
	}
	if(p==0) return sum;
	n=n-(p-1);
	long long sum2=0;
	for(long long i=0;i<M;i++) if(A[i]>=A[q]) sum2+=i;
	sum=sum+sum2*(n/(p-A[q]));
	int a=n%(p-A[q]);
	if(a==0) return sum;
	for(long long i=0;i<M;i++) if(A[i]>=A[q] && A[i]<(A[q]+a)) sum+=i;
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve();
}