#include <bits/stdc++.h>

using namespace std;
 
 

typedef long long ll;
//c++ templte for help............................................................................................................................................


template<typename... T>
void print1(T... t){
	((cout<<t<<" "),...);
}

template<typename... T>
void print2(T... t){
		vector<vector<ll>> ans={t...};
		for(ll i=0;i<(ll)ans.size();i++){
			if(i!=0) cout<<"\t\t";
			else cout<<"\t";
			for(ll j=0;j<(ll)ans[i].size();j++){
				cout<<ans[i][j]<<" ";
			}
			if(i!=(ll)ans.size()-1)
			cout<<endl;
		}
}	
#define deb(...) cout<<" [ "#__VA_ARGS__<<" : "; print1(__VA_ARGS__); cout<<"]"<<endl; 
#define vdeb(...) cout<<" [ "#__VA_ARGS__<<" : "; print2(__VA_ARGS__); cout<<"]"<<endl;





	
 
//for loop
//#define fo(i,n) for(int i=0;i<(ll)n;i++)
//#define Fo(i,k,n) for(int i=k;i<n;i++)
 
 
//to print vector element 
//template<typename T>
//void printV(T vec){
	//fo(i,vec.size()) cout<<vec[i]<<" "<<flush;
	//cout<<endl;
	//}
	
 
#define M int(1e9+7)
const int INF=1e9+5;
 
//iterate map
//template<typename T>
//void itR(T map){
	 //for(auto itr=map.begin();itr!=map.end();itr++){
				//deb(itr->first,itr->second);
			//}
	//cout<<endl;
//}


 

 
//c++ template for help...........................................................................................................................................

string solve(){
	int n;
	cin>>n;
	if(n>=30) return "Yes";
	return "No";
}


int main() {
	//stringstream ss;
	//ss<<"akhil";
	//cout<<ss.str()<<endl;
	cout<<setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//ofstream myfile;
	//myfile.open ("output.txt");
	

	//ll testCase;
	//cin>>testCase;
	//for(ll tt=0;tt<testCase;tt++){
		//solve();
		string ans=solve();
		cout<<ans<<endl;
	//}
	//myfile.close();
	return 0;
}
