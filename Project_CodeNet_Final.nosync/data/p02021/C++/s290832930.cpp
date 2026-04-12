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

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

signed main(){
	cout<<fixed<<setprecision(7);

	int N, A[200];
	
	cin>>N;
	
	rep(i,N){
		cin>>A[i];
	}
	for(int i = 1; i <= 101; i++){
		bool flag = true;
		int xx = 0;
		for(int j = 0; j < N; j++){
			xx += A[j];
			xx -= i;
			if(xx < 0)flag = false;
		}
		if(flag == false){
			cout<<i-1<<endl;
			break;
		}
	}
	
	return 0;
}
