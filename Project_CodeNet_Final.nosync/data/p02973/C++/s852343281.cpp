#include<bits/stdc++.h>
using namespace std;
int n,i,a[1000010],ans;
vector<int> que;
int bs(int l,int r,int num){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(num<=que[mid]) bs(mid+1,r,num);
	else bs(l,mid,num);
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		if(!que.empty()&&que[que.size()-1]<a[i]){
			que[bs(0,que.size()-1,a[i])]=a[i];
		}
		else{
			que.push_back(a[i]);
			ans++;
		}
	}
	cout<<ans;
}