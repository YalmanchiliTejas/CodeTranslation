//in the name of god
#include <bits/stdc++.h>
using namespace std;
#define MAX_N (int)1e5+20
#define INF 1e9+20
#define pb push_back
#define F first
#define S second
typedef long long LL;
typedef pair<int,int> pii;
const int delta=(int)1e9+7;
string s;
bool ac(){
	for(int i=0;i<s.size()-1;++i){
		if(s[i]=='A'&&s[i+1]=='C') return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>s;
	if(ac()) cout<<"Yes";
	else cout<<"No";
	return cout<<endl,0;
}