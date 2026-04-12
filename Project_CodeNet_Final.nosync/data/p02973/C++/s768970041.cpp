#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int a[300000];

int main(){
	int n;cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
	}
	multiset<P>se;
	rep(i,n){
		auto it=se.lower_bound(P(a[i],0));
		if(it==se.begin()){
			se.insert(P(a[i],1));
			continue;
		}
		it--;
		auto p=*it;
		se.erase(it);
		se.insert(P(a[i],p.second+1));
	}
	cout<<se.size()<<endl;
}