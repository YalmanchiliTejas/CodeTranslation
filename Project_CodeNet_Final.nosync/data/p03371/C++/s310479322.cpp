#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
	cout<<min(a+b,c*2)*min(x,y)+abs(x-y)*(x>y?min(a,c*2):min(b,c*2))<<"\n"s;
}