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
	
	// N = stoi(n);
	
	// for(int i = 1; i <= N; i++){
		// string num = to_string(i);
		// int con = count(num.begin(), num.end(), '0');
		
		// if(num.size() - con == K) {
			// cout<<i<<endl;
			// ans++;
		// }
	// }
	
	// cout<<ans<<endl;
	
	if(K == 1) {
		int con = ((int)n.size() - 1) * 9 + n[0] - '0';
		// cout<<"<> "<<n[0]<<" size "<<n.size()<<endl;
		cout<<con<<endl;
	} else if(K == 2) {
		// int con = ((int)n.size() - 1) * 9 * 9;
		int con =  9 * 9;
		int hoge = 0;
		
		
		// cout<<con<< " [] "<<(n.size()-0) * (n.size()-1) / 2<<endl;
		con *= (n.size()-0) * (n.size()-1) / 2;
		// for(int i = 0; i < (int)n.size()-1; i++){
			// hoge *= 9;
		// }
		
		// cout<<con<<" "<<hoge<<endl;
		con -= (9 - (n[0] - '0')) * (n.size()-1) * 9;
		
		int cc = 0;
		
		for(int i = 1; i < n.size(); i++){
			if(n[i] != '0' || n.size() == i + 1) {
				cc++;
				con -=  (9 - (n[i] - '0')) + hoge;
			}
			if(cc >= 1) break;
			// hoge /= 9;
			hoge += 9;
		}
		
		if(cc == 0) {
			
		}
		
		cout<<con<<endl;
	} 
	/* else if(K == 3) {
		int con =  9 * 9 * 9;
		int hoge = 0;
		cout<<con<< " [] "<<(n.size()-0) * (n.size()-1) * (n.size() - 2)/ 6<<endl;
		con *= (n.size()-0) * (n.size()-1) * (n.size() - 2)/ 6;
		cout<<con<<" "<<hoge<<endl;
		
		// con -= (9 - (n[0] - '0')) * (n.size()-1) * 9 * 9;
		con -= (9 - (n[0] - '0')) * 9 * 9 * (n.size()-1) * (n.size()-2) / 2;
		
		cout<<con<<endl;
		
		int cc = 0;
		
		for(int i = 1; i < n.size(); i++){
			// if(n[i] != '0' || n.size() == i + 1 || (cc == 0 && n.size() == i + 2)) {
			// if(n[i] != '0' || n.size() == i + 1 || (cc == 0 && n.size() == i + 2)) {
			if(n[i] != '0') {
				cc++;
				con -=  (9 - (n[i] - '0')) + hoge;
			}
			if(cc >= 2) break;
			// hoge /= 9;
			hoge += 9;
		}
		
		con += 9;
		
		cout<<con<<endl;


	}
	*/
	else if(K == 3) {
		int con =  9 * 9 * 9;
		int hoge = 0;
		// cout<<con<< " [] "<<(n.size()-1) * (n.size()-2) * (n.size() - 3)/ 6<<endl;
		con *= (n.size()-1) * (n.size()-2) * (n.size() - 3)/ 6;
		// cout<<con<<" "<<hoge<<endl;
		
		// con -= (9 - (n[0] - '0')) * (n.size()-1) * 9 * 9;
		// con -= (9 - (n[0] - '0')) * 9 * 9 * (n.size()-1) * (n.size()-2) / 2;
		
		// cout<<con<<endl;
		
		int cc = 0;
		
		for(int i = 0; i < n.size(); i++){
			if(n[i] != '0') {
				// cc++;
				// con -=  (9 - (n[i] - '0')) + hoge;
				if(cc == 0) {
					// cout<<((int)n.size() - i - 1) * ((int)n.size() - i - 2) / 2 * (n[i] - '1') * 9 * 9<<endl;
					con += ((int)n.size() - i - 1) * ((int)n.size() - i - 2) / 2 * (n[i] - '1') * 9 * 9;
				} else if(cc == 1) {
					// cout<<((int)n.size() - i - 1)  / 1 * (n[i] - '1') * 9<<endl;
					// cout<<((int)n.size() - i - 1)  / 1 * (n[i] - '1') * 9 + ((int)n.size() - i - 1) * ((int)n.size() - i - 2) / 2 * 9 * 9<<endl;
					con += ((int)n.size() - i - 1)  / 1 * (n[i] - '1') * 9 + ((int)n.size() - i - 1) * ((int)n.size() - i - 2) / 2 * 9 * 9;
				} else if(cc == 2) {
					// cout<< (n[i] - '0') + ((int)n.size() - i - 1) * 9<<endl;
					con += (n[i] - '0') + ((int)n.size() - i - 1) * 9;
				}
				cc++;
			}
			if(cc >= 3) break;
			// hoge /= 9;
			// hoge += 9;
		}
		
		// con += 9;
		
		cout<<con<<endl;
	}
	return 0;
}