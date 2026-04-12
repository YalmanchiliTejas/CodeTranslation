#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define pi 3.14159265358979323846
#define Endl endl
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	string st;
	cin>>st;
	int cnt = 0;
	for(int i=0;i<3;i++){ if(st[i] == 'B')cnt++; }
	if( cnt == 0 || cnt == 3 ){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
	return 0;
}