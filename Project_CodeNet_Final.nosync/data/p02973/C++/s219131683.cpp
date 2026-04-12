//int -> ll
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
typedef long long ll;
#define x first
#define y second
#define REP(i,sss,eee) for(int i=sss;i<=eee;++i)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
#define N 1000000007
using namespace __gnu_pbds;
using namespace std;
template <class T>
T MAX(T a, T b){return ((a>b)?a:b);}
template <class T>
T MIN(T a, T b){return ((a<b)?a:b);}
template <class T>
T MOD(T a){return ((a>=0)?a:(-1*a));}
template <class T>
void SWAP(T &a,T &b){T temp=a;a=b;b=temp;}
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/*****************default********************/
vi inp;
int lnds(vi &v){//Longest nondecreasing Sequence
	int n=v.size();
	if(n==0){return 0;}
	vi tail;tail.resize(n,0);
	int len=1;
	tail[0]=v[0];
	REP(i,1,n-1){
		if(v[i]>=tail[len-1]){
			tail[len++]=v[i];
		}
		else{
			auto it=upper_bound(tail.begin(),tail.begin()+len,v[i]);
			(*it)=v[i];
		}
	}
	return len;
}
int main(){
    speed
	int n;cin>>n;
	inp.resize(n);
	for(int i=0;i<n;++i){cin>>inp[i];}
	for(int i=0;i<n;++i){inp[i]=(1000000000-inp[i]);}
	cout<<lnds(inp)<<"\n";
}