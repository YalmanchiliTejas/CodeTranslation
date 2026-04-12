#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long int
#define N 200100
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int cnt1=0,cnt2=0;
	for(auto c:s){
		if(c=='A')
			cnt1++;
		else
			cnt2++;
	}
	if(cnt1>0 && cnt2>0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}