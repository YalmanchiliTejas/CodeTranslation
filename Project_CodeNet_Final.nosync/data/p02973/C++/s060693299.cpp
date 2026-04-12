#include <bits/stdc++.h>
#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define ll long long
#define inf LLONG_MAX
using namespace std;
int n,ans,k,a[100004];
vector<int> q;
signed main(){
	cin>>n;
	cin>>a[0];
	q.push_back(a[0]);
	for(int i=1;i<n;i++){
		cin>>a[i];
		int basho=lower_bound(q.begin(),q.end(),a[i])-q.begin()-1;
		if(basho<0){
			q.insert(q.begin(),a[i]);
		}else{
			q[basho]=a[i];
		}
	}
	cout<<q.size()<<endl;
	//for(int i=0;i<3;i++){cout<<q[i]<<endl;}
}
