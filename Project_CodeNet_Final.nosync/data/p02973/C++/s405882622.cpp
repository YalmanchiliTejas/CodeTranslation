#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<queue>
#include<set>
#define FOR(i,l,r) for(int i=(l),i##R=(r);i<=i##R;i++)
#define DOR(i,r,l) for(int i=(r),i##L=(l);i>=i##L;i--)
#define loop(i,n) for(int i=0,i##R=(n);i<i##R;i++)
#define mms(a,x) memset(a,x,sizeof a)
#define pb push_back
using namespace std;
typedef long long ll;
template<typename A,typename B>inline void chkmax(A &x,const B y){if(x<y)x=y;}
template<typename A,typename B>inline void chkmin(A &x,const B y){if(x>y)x=y;}
const int N=2e5+5;
int n;
int a[N],b[N];
multiset<int>S;
multiset<int>::iterator it;
int h;
int main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",&a[i]);
	FOR(i,1,n){
		if(S.empty())S.insert(a[i]);
		else {
			it=S.lower_bound(a[i]);
			if(it==S.begin())S.insert(a[i]);
			else {
				it--;
				S.erase(it);
				S.insert(a[i]);
			}
		}
	}
	printf("%d\n",S.size());
	return 0;
}