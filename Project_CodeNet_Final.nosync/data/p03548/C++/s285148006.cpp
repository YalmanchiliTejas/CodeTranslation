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
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,c,ans; cin>>a>>b>>c; a-=c;
	ans=(a)/(b+c);
	cout<<ans;
	return cout<<endl,0;
}