#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
int main(){
	ll h,w;
	cin>>h>>w;
	int cnt=0;
	for(ll i=0;i<h;i++){
		string str;
		cin>>str;
		for(int j=0;j<w;j++){
			if(str[j] == '#')cnt++;
		}
	}
	if(cnt == h+w-1)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}