#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;
typedef vector<vll> vvll;


#define F first
#define S second
#define pb push_back
#define mp make_pair

// don't edit before this line 



//const ll inf = (ll)1e9 + 7; 



ll n;
vll arr;
pll memo[3001][3001][2];
bool check[3001][3001][2];

pll func(int i,int j,int t){

	if(i==j)
	{
		if(t==0)
			return mp(arr[i],0);
		else
			return mp(0,arr[i]);
	}
	
	if(check[i][j][t])
		return memo[i][j][t];
	

	check[i][j][t]=true;
	if(t==0)
	{
		auto xx = func(i+1,j,1-t);
		auto yy = func(i,j-1,1-t);
		xx.first+=arr[i];
		yy.first+=arr[j];
		//cout<<xx.F<<" "<<xx.S<<" " <<yy.F<<" "<<yy.S<<"\n";
		if(xx.first > yy.first )
			return memo[i][j][t]=xx;
		else
			return memo[i][j][t]=yy;
	}
	else
	{

		auto xx = func(i+1,j,1-t);
		auto yy = func(i,j-1,1-t);
		xx.second+=arr[i];
		yy.second+=arr[j];
		//cout<<xx.F<<" "<<xx.S<<" " <<yy.F<<" "<<yy.S<<"\n";
		if(xx.second > yy.second)
			return memo[i][j][t]=xx;
		else
			return memo[i][j][t]=yy;
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cout.setf(ios::fixed), cout.precision(20);

	cin >> n;
	arr.resize(n);

	
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	for(int i=0;i<3001;i++)
		for(int j=0;j<3001;j++){
			check[i][j][0]=false;
			check[i][j][1]=false;
		}
	auto xx = func(0,n-1,0);
	cout<<xx.F-xx.S<<"\n";
	
	return 0;
}
