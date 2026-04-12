//*INDENT-OFF*
#include<bits/stdc++.h>
using namespace std;
template<typename V>
bool tomin(V&x,V y){if(y<x){x=y;return true;}return false;}
template<typename V>
bool tomax(V&x,V y){if(x<y){x=y;return true;}return false;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
#pragma GCC optimize(3)
#define lowbit(x) ((x)&-(x))
//*INDENT-ON*
const int M=1e5+5;
int n,A[M],B;
multiset<int>S;
multiset<int>::iterator it;
int main(){
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		it=S.lower_bound(A[i]);
		if(S.size()&&it!=S.begin())
			S.erase(--it);
		else ans++;
		S.insert(A[i]);
	}
	printf("%d\n",ans);
	return 0;
}