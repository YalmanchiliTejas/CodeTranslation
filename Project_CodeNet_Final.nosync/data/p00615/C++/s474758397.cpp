#include <iostream>
#include <set>
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		multiset<int> t;
		t.insert(0);
		for(int i=0,a;i<n+m;++i){
			cin>>a;
			t.insert(a);
		}
		int maxd=0;
		multiset<int>::iterator it1=t.begin(),it2=t.begin();
		++it2;
		for(;it2!=t.end();){
			if(*it2-*it1>maxd)maxd=*it2-*it1;
			++it1;
			++it2;
		}
		cout<<maxd<<"\n";
	}
	return 0;
}