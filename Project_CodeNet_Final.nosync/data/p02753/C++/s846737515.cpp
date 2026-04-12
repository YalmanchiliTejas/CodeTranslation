#include<bits/stdc++.h>
#define N 40010
using namespace std;
int a[2];
int main(){
	string s;
	cin>>s;
	a[s[0]-'A']++;
	a[s[1]-'A']++;
	a[s[2]-'A']++;
	if(a[0]==0||a[1]==0){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
}