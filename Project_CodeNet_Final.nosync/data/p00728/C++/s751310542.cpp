#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
	int n;
	while(cin>>n,n!=0){
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		cout<<(accumulate(all(a),0)-*max_element(all(a))-*min_element(all(a)))/(n-2)<<endl;
	}
	return 0;
}
