#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int,int>P;
typedef pair<int,P>P2;
#define F first
#define S second

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

signed main(){
	int n;
	cin>>n;
	int a[n];
	r(i,n)cin>>a[i];

	multiset<int>st;

	for(int i=n-1;i>=0;i--){
		set<int>::iterator it = st.upper_bound(a[i]);
		if(it==st.end()) st.insert(a[i]);
		else{
			st.erase(it);
			st.insert(a[i]);
		}
		//cout<<st.size()<<endl;
	}

	cout<<st.size()<<endl;
}