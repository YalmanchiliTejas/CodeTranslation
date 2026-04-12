#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, A, ans = 0;
	map<int,int> x;
	cin>>N;
	
	
	for(int i = 0; i < N; i++){
		cin>>A;
		int a = A;
		
		for(int j = 2; j * j <= A; j++){
			if(A%j == 0){
				x[j] += a;
				while(A%j == 0){
					A /= j;
				}
			}
		}
		
		if(A != 1){
			x[A] += a;
		}
	}
	
	for(pair<int,int> p : x){
		ans = max(ans, p.second);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
