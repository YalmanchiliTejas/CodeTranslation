#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
    multiset<int,greater<int>> cas;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		auto itr=cas.upper_bound(a);
		//cout<<*itr<<endl;
		//for(auto ite=cas.begin();ite!=cas.end();ite++)cout<<*ite<<endl;
		if(cas.end()!=itr)cas.erase(itr);
		cas.insert(a);
	}
	//for(auto ite=cas.begin();ite!=cas.end();ite++)cout<<*ite<<endl;
	cout<<cas.size()<<endl;
}
