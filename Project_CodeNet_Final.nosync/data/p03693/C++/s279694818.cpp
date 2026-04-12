#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,g,b;
	cin>>r>>g>>b;
	cout<<((b+g*10)%4?"NO\n":"YES\n");
}