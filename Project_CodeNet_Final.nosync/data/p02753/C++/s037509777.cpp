#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;


#define LL long long
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int main() {

ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	int t=1;
	//cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s=="AAA" || s=="BBB")
			cout<<"No"<<'\n';
		else
			cout<<"Yes"<<'\n';
	}



return 0;
}