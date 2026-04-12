#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

clock_t present = clock();
void complexiti(){
	present = clock() - present;
	cerr << "TIME : " << float(present)/CLOCKS_PER_SEC << '\n';
}

int INF = (int)1 << 30;
vector<int> v;

void longestNonDecreasingSubsequenceSize(){
	int n = v.size();
	vector<int> arr(n,INF);
	for(auto i:v){
		*upper_bound(arr.begin() , arr.end() , i) = i;
	}
	cout << lower_bound(arr.begin() , arr.end() , INF) - arr.begin() << endl;
}

void solver(){
	//~ type your code here
	int n;
	cin >> n;
	v.resize(n);
	for(auto &i:v){
		cin >> i;
	}
	reverse(v.begin() , v.end());
	longestNonDecreasingSubsequenceSize();
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int queries = 1;
	//~ cin >> queries;
	for(int i = 0 ; i < queries ; ++i){
		solver();
	}
	complexiti();
	return 0;
}
