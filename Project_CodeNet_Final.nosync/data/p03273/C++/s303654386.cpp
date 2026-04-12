#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int H, W;
	vector<string> a, ans1, ans2;
	
	cin>>H>>W;
	
	a.resize(H);
	
	for(int i = 0; i < H; i++){
		cin>>a[i];
		if(count(a[i].begin(), a[i].end(), '.') != W) ans1.push_back(a[i]);
	}
	
	ans2.resize(ans1.size());
	
	for(int i = 0; i < W; i++){
		int con = 0;
		for(int j = 0; j < ans1.size(); j++){
			con += ans1[j][i] == '.';
		}
		
		if(con != ans1.size()){
			for(int j = 0; j < ans1.size(); j++){
				ans2[j].push_back(ans1[j][i]);
			}
		}
	}
	
	for(string s : ans2){
		cout<<s<<endl;
	}
	return 0;
}