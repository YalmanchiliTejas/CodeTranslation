#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
	int rem;
	if(x>y)rem=min(a,c*2);
	else rem=min(b,c*2);
	cout<<min(a+b,c*2)*min(x,y)+abs(x-y)*rem<<"\n"s;
}