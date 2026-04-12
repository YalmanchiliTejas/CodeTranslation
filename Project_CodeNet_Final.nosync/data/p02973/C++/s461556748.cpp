#include <bits/stdc++.h>
using namespace std;
#define M 100005
typedef long long LL;
template<class T>void tomax(T &x,T y){
	if(x<y)x=y;	
}
template<class T>void tomin(T &x,T y){
	if(x>y)x=y;	
}
multiset<int>T;
multiset<int>::iterator it;
int A[M];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	T.insert(A[1]);
	int ans=1;
	for(int i=2;i<=n;i++){
		it=T.lower_bound(A[i]);
		if(it==T.begin())ans++;
		else it--,T.erase(it);
		T.insert(A[i]);
	}
	cout<<ans;
	return 0;
}