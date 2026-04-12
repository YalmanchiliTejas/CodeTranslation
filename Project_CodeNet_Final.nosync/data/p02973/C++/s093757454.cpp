#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

#define MAX


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int ans = 1;
	int  N;
	vector<int> l, A, B;
	
	
	cin>>N;
	
	A.resize(N);

	for(int i = 0; i < N; i++){
		cin>>A[i];
	}
	reverse(A.begin(), A.end());
	
	for(int i = 0; i < N; i++){
		if(l.size() == 0 || l.back() <= A[i]){
			l.push_back(A[i]);
		} else {
			int it = upper_bound(l.begin(), l.end(), A[i]) - l.begin();
			l[it] = A[i];
		}
	}
	
	
	cout<<l.size()<<endl;
	
	return 0;
}