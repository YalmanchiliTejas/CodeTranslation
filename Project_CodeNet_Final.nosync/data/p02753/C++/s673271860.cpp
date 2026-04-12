#include<bits/stdc++.h>
using namespace std;
int main(){
	char a;
	set<char>q;
	for(int i=0;i<3;i++)cin>>a,q.insert(a);
	if(q.size()==2)cout<<"Yes"<<"\n";
	else cout<<"No"<<"\n";
	return 0;
}
