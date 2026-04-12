#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define INF LLONG_MAX/3
#define P std::pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int k,a,b;
signed main(){
	cin>>k>>a>>b;
	if(k<=a)cout<<1<<endl;
	else if(a<=b)cout<<-1<<endl;
	else{
		int c=(k-a+(a-b)-1)/(a-b);
		cout<<c*2+1<<endl;
	}
    return 0;
}