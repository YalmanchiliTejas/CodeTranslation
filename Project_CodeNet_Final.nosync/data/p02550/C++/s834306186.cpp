#include<iostream>
#include<vector>
#include<map>
using namespace std;
long long n,x,m,a;
vector<long long> v;
vector<long long> v1;
map<long long,int> ma;
long long mod;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>x>>m;
	mod=m;
	long long idx=n,ans=0;
	a=x;
	long long xx=n;
	for(int i=1;i<=n;i++){
		xx=i;
		if(ma[a]){
			idx=ma[a]-1;
			break;
		}
		ma[a]=i;
		ans+=a;
		v.push_back(a);
		a=a*a%mod;
	}
	int  len=v.size();
	for(int i=0;i<len;i++) if(i>=idx) v1.push_back(v[i]);
	long long cnt=n-xx+1;/*?*/
	long long sum=0;
	for(int i=0;i<v1.size();i++) sum+=v1[i];
	if(v1.size()){
		ans+=cnt/v1.size()*sum;
		for(int i=0;i<cnt%v1.size();i++) ans+=v1[i];
	}
	cout<<ans;
}