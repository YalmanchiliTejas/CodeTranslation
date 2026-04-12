#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define INF 1000000009
int n;
ll a[100005],b[100005];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	int i=0,j=n-1,p=0;
	while(i<j){
		b[p++]=a[i++];
		b[p++]=a[j--];
	}
	if (i==j) b[p++]=a[i];
	ll ans=0;
	rep(ii,p-1) ans+=abs(b[ii]-b[ii+1]);
	if (abs(b[p-1]-b[p-2])<abs(b[p-1]-b[0])) ans+=abs(b[p-1]-b[0])-abs(b[p-1]-b[p-2]);
	if (i==j){
		ll newans=0;
		i=0,j=n-1,p=0;
		while(i<j){
			b[p++]=a[j--];
			b[p++]=a[i++];
		}
		b[p++]=a[i];
		rep(ii,p-1) newans+=abs(b[ii]-b[ii+1]);
		if (abs(b[p-1]-b[p-2])<abs(b[p-1]-b[0])) newans+=abs(b[p-1]-b[0])-abs(b[p-1]-b[p-2]);
		ans=max(ans,newans);
	}
	cout<<ans;
	return 0;
}