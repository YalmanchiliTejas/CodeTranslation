#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cctype>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
//#include<windows.h>
//#include<time.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mer make_pair
#define mme memset
using namespace std;

const double pie1=3.1415926;//π1
const double pie2=3.14159265358979;//π2
const double pie3=3.14159265358979323846;//π3
const int vbi=999999999;
const int vli=-vbi;
const long long vbl=999999999999999999;
const long long vll=-vbl;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
typedef pair<pii,pii> pi4;
typedef pair<pll,ll> plll;
typedef pair<int,pii> ipii;
typedef pair<ll,pll> lpll;
typedef pair<pll,pll> pl4;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef set<int> sti;
typedef set<ll> stl;
typedef set<pii> spi;
typedef set<pll> spl;
priority_queue<int> pqi;
priority_queue<ll> pql;
queue<int> qi;
queue<ll> ql;

/*void bin_v(){
	char bin[1000];
	gets(bin);
}*/

bool pss(int a){
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)
			return false;
	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////

int n;
struct ac{
	int x,y,z;
}a[100010];
int bcj[100010];

int cmp(ac v,ac r){
	return v.x<r.x;
}

int cmp2(ac v,ac r){
	return v.y<r.y;
}

vector<pair<int,pii> > v;

int father(int b){
	if(bcj[b]==b)
		return b;
	bcj[b]=father(bcj[b]);
	return bcj[b];
}

int main(){
	//my name is Veex
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].z=i;
		bcj[i]=i;
	}
	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
		v.pb(mer(a[i+1].x-a[i].x,mer(a[i].z,a[i+1].z)));
	
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<n;i++)
		v.pb(mer(a[i+1].y-a[i].y,mer(a[i].z,a[i+1].z)));
	
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=0;i<v.size();i++){
		if(father(v[i].se.fi)==father(v[i].se.se))
			continue;
		sum+=v[i].fi;
		bcj[father(v[i].se.fi)]=father(v[i].se.se);
	}
	cout<<sum;
	return 0;
}
/*
6
8 3
4 9
12 19
18 1
13 5
7 6
*/