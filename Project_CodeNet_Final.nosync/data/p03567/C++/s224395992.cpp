
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef struct pair<int,int> P;
typedef struct pair<int,P> P2;

vector<ll> v[28];
vector<ll> v2;

int dp[100001]={};
const ll INF=1000000000000000001;
int main() {

	string s;
	cin>>s;
	int ls=s.length();
	bool flg=false;
	for(int i=1;i<ls;++i){
		if(s[i]=='C'&&s[i-1]=='A')flg=true;
	}
	if(flg){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}
