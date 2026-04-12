#include<bits/stdc++.h>
using namespace std;

pair<long long int,long long int> p[200000];

long long int a[2][200001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=0;i<n;i++)
		if(p[i].first<p[i].second)
			swap(p[i].first,p[i].second);
	sort(p,p+n,greater<pair<long long int,long long int> >());
	a[0][n-1]=p[n-1].second;
	a[1][n-1]=p[n-1].first;
	for(int i=n-2;i>=0;i--){
		a[1][i]=a[1][i+1];
		a[0][i]=min((long long int) p[i].second,a[0][i+1]);
	}
	a[0][n]=a[1][n]=2e9;
	long long int R=p[0].first,B=p[0].second,r=p[0].first,b=p[0].second,ans=6e18;
	for(int i=1;i<n;i++){
		
		ans=min(ans,(R-min(min(a[0][i+1],r),p[i].second))*(max(B,p[i].first)-min(p[i].first,min(a[1][i+1],b))));
		ans=min(ans,(R-min(min(a[1][i+1],r),p[i].second))*(max(B,p[i].first)-min(p[i].first,min(a[0][i+1],b))));
		
		R=max(R,p[i].first);r=min(r,p[i].first);
		B=max(B,p[i].second);b=min(b,p[i].second);
	}
	ans=min(ans,(R-r)*(B-b));
	cout<<ans<<endl;
}