#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll=long long;

int main()
{
	int N,res=0;
	cin>>N;

	multiset<int> st;
	rep(i,N){
		int a;
		cin>>a;

		auto itr = st.lower_bound(a);
		if(itr==st.begin()){
			res++;
			st.insert(a);
		}
		else{
			--itr;
			st.erase(itr);
			st.insert(a);
		}
	}
	cout<<res<<endl;
	return 0;
}
