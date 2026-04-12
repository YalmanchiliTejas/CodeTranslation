#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pll;
pll arr[100005],arr1[100005];
vector<pair<ll,pll> > vect;
int root[100005];
int _rank[100005];

int findroot(int a){
	while(a!=root[a])
		a=root[a];
	return a;
}

void uni(int a, int b){
	int x=findroot(a);
	int y=findroot(b);
	if (_rank[x]>_rank[y]){
		root[y]=x;
	}
	else{
		root[x]=y;
		if (_rank[x]==_rank[y])
			_rank[y]+=1;
	}
}


int main(){
	for(int i=0;i<100005;i++)
		root[i]=i;
	int n; ll a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		arr[i].f=a; arr[i].s=i;
		arr1[i].f=b; arr1[i].s=i;
	}
	sort(arr,arr+n);
	for(int i=0;i<n-1;i++){
		vect.pb(mp((arr[i+1].f-arr[i].f),mp(arr[i+1].s,arr[i].s)));
	}
	sort(arr1,arr1+n);
	for(int i=0;i<n-1;i++){
		vect.pb(mp((arr1[i+1].f-arr1[i].f),mp(arr1[i+1].s,arr1[i].s)));
	}		
	ll ans=0;
	int len=vect.size();
	sort(vect.begin(),vect.end());
	for(int i=0;i<len;i++){
		if(findroot(vect[i].s.f)!=findroot(vect[i].s.s)){
			uni(vect[i].s.f,vect[i].s.s);
			ans+=vect[i].f;
		}
	}

	cout << ans << endl;

	return 0;
}