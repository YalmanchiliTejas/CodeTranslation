#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i) 
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define all(c)  ((c).begin()), ((c).end())
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	FOR(i,0,s.length()-1){
		if(s[i]=='A'&&s[i+1]=='C'){
			cout<<"Yes";
			exit(0);
		}
	}
	cout<<"No";
}