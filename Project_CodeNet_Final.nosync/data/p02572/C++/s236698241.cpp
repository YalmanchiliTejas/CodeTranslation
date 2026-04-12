#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
#define mod 1000000007
#define all(x) (x).begin(),(x).end()

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);	
	long long ans=0;
	for(int &i:v){
		cin>>i;
		ans += i;
      	ans %= mod;
	}	
	long resp = 0;
	for(size_t i:v){
		ans -= i;      
		if(ans < 0) ans += mod;          
		resp += (i * ans);
        resp %= mod;
	}	
	cout<<resp<<endl;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
