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
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

#define MAX

signed main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	// cout<<fixed<<setprecision(10);
	
	int N, u, v, md, now, dis = 0;
	vector<pair<int,pair<int,int>>> p;
	vector<pair<int,int>> in;
	vector<int> ans;
	
	cin>>N>>u>>v;
	
	cout<<"? "<<u<<" "<<v<<endl;
	cout.flush();
	cin>>md;
	
	for(int i = 1; i <= N; i++){
		if(i == u || i == v) continue;
		int a, b;
		cout<<"? "<<u<<" "<<i<<endl;
		cout.flush();
		
		cin>>b;
		
		cout<<"? "<<v<<" "<<i<<endl;
		cout.flush();
		
		cin>>a;
		
		if(a + b == md){
			in.push_back(make_pair(b,i));
		}
	}
	
	sort(in.begin(), in.end());
	
	ans.push_back(u);
	now = u;
	
	for(int i = 0; i < in.size(); i++){// cout<<"in "<<in[i].second<<endl;
		int a, b;
		
		cout<<"? "<<v<<" "<<in[i].second<<endl;
		cout.flush();
		cin>>a;
		
		cout<<"? "<<now<<" "<<in[i].second<<endl;
		cout.flush();
		cin>>b;
		
		if(b+a+dis == md){
			ans.push_back(in[i].second);
			now = in[i].second;
			dis = in[i].first;
		}
	}
	
	ans.push_back(v);
	
	cout<<"!";
	
	for(int i = 0; i < ans.size(); i++){
		cout<<" "<<ans[i];
	}
	cout<<endl;
	cout.flush();
	
	return 0;
}
