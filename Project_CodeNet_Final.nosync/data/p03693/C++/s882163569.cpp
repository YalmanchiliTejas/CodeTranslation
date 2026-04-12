//
#include <bits/stdc++.h>
using namespace std;
#define ote(x) cout<<(x)<<endl

int main(){
	int r,g,b; cin>>r>>g>>b;
	ote((r*100+g*10+b)%4==0? "YES":"NO");
}
