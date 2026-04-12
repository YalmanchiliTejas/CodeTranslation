#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll=long long;
static const ll mod = 1e9 + 7;
static  ll INF = 1e9;
using namespace std;

signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
