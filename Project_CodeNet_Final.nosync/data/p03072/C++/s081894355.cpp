 #include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF ((long long)1e18)
#define MOD ((int)1e9+7)
#define endl "\n"

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

#define MAX 110

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, con = 0;
	int H[MAX] = {};
	
	cin>>N;
	
	for(int i = 0; i < N; i++){
		cin>>H[i];
		bool flag = true;
		for(int j = 0; j < i; j++){
			if(H[i] < H[j]){
				// cout<<H[i]<<" "<<H[j]<<endl;
				flag = false;
			}
		}
		if(flag) con++;
		// cout<<i<<" "<<flag<<endl;
	}
	cout<<con<<endl;
	return 0;
}
 