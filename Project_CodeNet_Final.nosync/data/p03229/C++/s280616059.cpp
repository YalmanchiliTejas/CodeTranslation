#include<bits/stdc++.h>
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=100010;
int n;
ll a[maxn],ans,maxx,tep,b[maxn];
priority_queue<ll >qmax;
priority_queue<ll ,vector<ll>,greater<ll> >qmin;
void cal(){
	ans=0;
	ll p1=qmin.top(),p2=qmin.top();
	qmin.pop();
	int flag=0;
	while((!qmin.empty())||(!qmax.empty())){
		if(flag==0){
			flag=1;
			if(!qmax.empty()){
				ans+=abs(qmax.top()-p1);
				p1=qmax.top();
				qmax.pop();
			}
			if(!qmax.empty()){
				ans+=abs(qmax.top()-p2);
				p2=qmax.top();
				qmax.pop();
			}
		}else if(flag==1){
			flag=0;
			if(!qmin.empty()){
				ans+=abs(qmin.top()-p1);
				p1=qmin.top();
				qmin.pop();
			}
			if(!qmin.empty()){
				ans+=abs(qmin.top()-p2);
				p2=qmin.top();
				qmin.pop();
			}
		}
	}
	maxx=max(maxx,ans);
}
int main() {
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=(n/2);i++){
		qmin.push(a[i]);
	}
	for(int i=(n/2)+1;i<=n;i++)
	{
		qmax.push(a[i]);
	}
	cal();
	for(int i=1;i<=(n-n/2);i++){
		qmin.push(a[i]);
	}
	for(int i=(n-n/2)+1;i<=n;i++)
	{
		qmax.push(a[i]);
	}
	cal();
	printf("%lld\n",maxx);
}