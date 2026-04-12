#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<cctype>
#include<cmath>
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
#define pq priority_queue
#define rep(i,n) for (int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define INF 200000009
#define init(x) memset(x,0,sizeof(x))
int n;
int m1,m2;
pii a[200005];
int id[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;++i){
    	cin>>a[i].F;
    	a[i].S=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1;i<=n;++i) id[a[i].S]=i;
	m1=a[n/2].F;m2=a[n/2+1].F;
	for (int i=1;i<=n;++i){
		if (id[i]<=n/2) cout<<m2<<endl;
		else if (id[i]>=n/2+1) cout<<m1<<endl;
	}
    return 0; 
}