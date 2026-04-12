#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[100005];

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++){
		cin >> A[i];
	}
	set<pair<long long, long long>> cur;

	for(long long i = 0; i < N; i++){
		long long num = A[i];

		auto it = cur.lower_bound(make_pair(num, -1));
		if(it == cur.begin()){
			cur.insert(make_pair(num, i));
		}else{
			it--;
			cur.erase(it);
			cur.insert(make_pair(num, i));
		}
	}
	cout << cur.size() << endl;
}