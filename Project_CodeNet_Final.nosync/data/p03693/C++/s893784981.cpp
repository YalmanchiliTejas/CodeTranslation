#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int r,g,b;cin>>r>>g>>b;
  	cout<<((100*r+10*g+b)%4==0?"YES":"NO")<<endl;
}