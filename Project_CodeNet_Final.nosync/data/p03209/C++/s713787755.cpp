#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)

#define yn(f) (f?"Yes":"No")
#define YN(f) (f?"YES":"NO")


int N, X, ans = 1;
int temp[100] = {1,};
int temp2[100] = {1,};

int solve(int x, int le){//cout<<x<<" "<<le<<endl;
	if(le == 0)return x;//cout<<"a"<<endl;
	if(x == 1)return 0;
	if(x == temp2[le]) return temp[le];//cout<<"b"<<endl;
	if(x*2 < temp2[le]) return solve(x-1,le-1);//cout<<"c"<<endl;
	if(x*2 == temp2[le]+1) return temp[le-1]+1;//cout<<"d"<<endl;
	return solve(x-temp2[le-1]-2,le-1)+temp[le-1]+1;
}
signed main(){
	cout<<fixed<<setprecision(7);
	

	
	cin>>N>>X;
	
	for(int i = 1; i <= N; i++){
		temp[i] = temp[i-1]*2+1;
		temp2[i] = temp2[i-1]*2+3;
	}
	cout<<solve(X,N)<<endl;
	
	
	return 0;
}