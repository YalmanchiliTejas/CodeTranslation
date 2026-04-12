#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()	
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000000;
typedef pair<int,int> P;
int main(){
	string s;cin>>s;
	bool ans=false;
	for(int i=0;i<s.length()-1;i++){
		if(s.substr(i,2)=="AC"){
			ans=true;
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}