#include<bits/stdc++.h>
using namespace std;
int N;
 int A [ 101010 ];

int V [ 101010 ];
 int num [ 101010 ];

void solve(){
	 int i,j,k,l,r,x,y; string s;
	
	
	cin >> N;
	multiset < int > M;
	for (int i=1;i<=N;i++){
		cin >> x;
		auto it = M.lower_bound(x);
		 if(it!= M.begin())M.erase(--it);
		M.insert(x);
	}
	cout << M.size()<< endl;
	
}

int main()
{
	solve();
	return 0;
}