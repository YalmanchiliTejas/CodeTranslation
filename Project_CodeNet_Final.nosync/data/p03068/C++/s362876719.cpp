#include <bits/stdc++.h>
#include <string>
using namespace std ;

int main(){
	int n,s;
	string a;
	cin>>n;
	cin>>a;
	cin>>s;
	for(int i=0;i<=a.length();i++){
		if(a[i]!=a[s-1]){
			a[i]='*';
		}
	}
	cout<<a<<"\n";
}
