#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,string>P;

int main() {
	int n;cin>>n;
	while(1){
		vector<P>v;
		rep(i,n){
			string s;int a,b,c;
			cin>>s>>a>>b>>c;
			v.push_back(P(a*3+c*1,s));
		}
		stable_sort(v.begin(),v.end(),[](P a,P b){return a.first>b.first;});
		for(P p:v){
			cout<<p.second<<','<<p.first<<endl;
		}
		cin>>n;
		if(!n)return 0;
		else cout<<endl;
	}
}