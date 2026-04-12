#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	while(true){
		int n; cin>>n;
		if(n==0)break;
		vector<int>s(n); for(auto&&i:s)cin>>i;
		sort(s.begin(),s.end());
		cout<<accumulate(s.begin()+1,s.end()-1,0)/(n-2)<<"\n"s;
	}
}
