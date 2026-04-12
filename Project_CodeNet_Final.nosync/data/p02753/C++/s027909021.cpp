#include<bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rep2(i,a,b) for(ll i=a;i>=b;i--)

int main(int argc, char** argv) {
	string s;
	cin>>s;
	int fg=0,fg1=0;
	rep(i,0,s.length()-1){
	if(s[i]=='A')fg++;else if(s[i]=='B')fg1++;}
	if(fg&&fg1)
	cout<<"Yes";
	else cout<<"No";
	return 0;
}