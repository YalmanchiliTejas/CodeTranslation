#include<bits/stdc++.h> 
using namespace std;
list<int>l;

int main(){
	int n,a;
	int t=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(t) l.push_back(a);
		else l.push_front(a);
		t=!t;
	}
	
	if(!t)l.reverse();
	for(auto i=l.begin();i!=l.end();++i)
		cout<<*i<<" ";
	return 0;
}