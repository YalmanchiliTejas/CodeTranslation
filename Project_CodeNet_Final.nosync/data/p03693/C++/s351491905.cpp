#include <bits/stdc++.h>
using namespace std;
# define ll long long int
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int a,b,c;
	cin>>a>>b>>c;
	a=100*a+10*b+c;
	if(a%4==0){
		cout<<"YES";
		return 0;
	}cout<<"NO";
}
