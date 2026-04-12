#include <bits/stdc++.h>

using namespace std;

typedef long long int lo;
typedef pair<int,int> PII;

#define FOR for(int i=1;i<=n;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const lo li = 100005;
const lo inf = 1000000000;

int n,m,k;
int b[li],a[li];
int cev;
vector<int> v;
vector<int> vv;

int main(){
	scanf("%d",&n);
	FOR{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i+=2){
		v.pb(a[i]);
	}
	for(int i=2;i<=n;i+=2){
		vv.pb(a[i]);
	}
	if(n%2==1){
		//~ sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		//~ sort(vv.begin(),vv.end());
		for(int i=0;i<(int)v.size();i++)printf("%d ",v[i]);
		for(int i=0;i<(int)vv.size();i++)printf("%d ",vv[i]);
		printf("\n");
	}
	else{
		//~ sort(v.begin(),v.end());
		reverse(vv.begin(),vv.end());
		//~ sort(vv.begin(),vv.end());
		for(int i=0;i<(int)vv.size();i++)printf("%d ",vv[i]);
		for(int i=0;i<(int)v.size();i++)printf("%d ",v[i]);
		
		printf("\n");
	}
	return 0;
}

