#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

constexpr long long INF = (long long)1e18;
constexpr long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, K;
	int ans = 0;
	string n;
	
	cin>>n>>K;
	
	if(K == 1) {
		int con = ((int)n.size() - 1) * 9 + n[0] - '0';
		
		cout<<con<<endl;
	} else if(K == 2) {
		int con =  9 * 9 * (n.size()-0) * (n.size()-1) / 2 - (9 - (n[0] - '0')) * (n.size()-1) * 9;
		for(int i = 1, cc = 0, hoge = 0; i < n.size() && cc < 1; i++, hoge += 9){
			if(n[i] != '0' || n.size() == i + 1) {
				cc++;
				con -=  (9 - (n[i] - '0')) + hoge;
			}
		}
		
		cout<<con<<endl;
	} else if(K == 3) {
		int con =  9 * 9 * 9 *  (n.size()-1) * (n.size()-2) * (n.size() - 3)/ 6;
		
		for(int i = 0, cc = 0; i < n.size() && cc < 3; i++){
			if(n[i] != '0') {
				if(cc == 0) con += ((int)n.size() - i - 1) * ((int)n.size() - i - 2) / 2 * (n[i] - '1') * 9 * 9;
				else if(cc == 1) con += ((int)n.size() - i - 1)  / 1 * (n[i] - '1') * 9 + ((int)n.size() - i - 1) * ((int)n.size() - i - 2) / 2 * 9 * 9;
				else if(cc == 2) con += (n[i] - '0') + ((int)n.size() - i - 1) * 9;
				cc++;
			}
		}
		
		cout<<con<<endl;
	}
	
	return 0;
}