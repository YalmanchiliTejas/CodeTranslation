#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x,y,z;
	cin>>x>>y>>z;
	int tmp=(x/(y+z));
	if(x%(y+z)>=z)
		cout<<tmp<<endl;
	else
		cout<<tmp-1<<endl;
}
