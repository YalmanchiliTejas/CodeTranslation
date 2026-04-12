
/*
Author: Srinjoy
Language: C++ 17
*/
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define ZERO(a) memset(a,0,sizeof(a))
#define fileinput(s) freopen(s,"r",stdin)
#define MINUS(a) memset(a,0xff,sizeof(a))
typedef long long ll;
const ll mod = 1000000007;

template<class T>
istream& operator >> (istream& in, vector<T>& v){ for (auto &x : v) { in >> x; } return in; }
 
template<class T>
istream& operator >> (istream& in, pair<T, T> & v){ in >> v.fi >> v.se;return in; }

void printArr(vector<int> arr){
	cout<<"\n------------------------------------\n";

	for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
	
	cout<<"\n------------------------------------\n";
}

int dp[1001][100][2]; 
int K;

int solve(int pos, int cnt, int tight, vector<int> num) { 
	
	if (pos == num.size()) { 
		if (cnt <= K) 
			return 1; 
		return 0; 
	} 

	
	if (dp[pos][cnt][tight] != -1) 
		return dp[pos][cnt][tight]; 

	int ans = 0; 

	int limit = (tight ? 9 : num[pos]); 

	for (int dig = 0; dig <= limit; dig++) { 
		int currCnt = cnt; 

		if (dig != 0) 
			currCnt++; 

		int currTight = tight; 

		
		if (dig < num[pos]) 
			currTight = 1; 

		ans += solve(pos + 1, currCnt, currTight, num); 
	}

	return dp[pos][cnt][tight] = ans;

}

int calc(string s1){
	vector<int> nums;
	for(char c:s1){
		nums.push_back( (int)(c - '0') );
	}
	//printArr(nums);

	memset(dp, -1, sizeof(dp)); 
	return solve(0,0,0,nums);
} 


int main(){
	optimiza_io
	
	string n;
	cin>>n;
	int k;	
	cin>>k;

	vector<int> nums;

	string start = "0";

	K=k;
	int p1 = calc(n) - calc(start);
	
	K=k-1;
	int p2 = calc(n) - calc(start);

	cout<< abs(p2-p1)<<endl;


	
}