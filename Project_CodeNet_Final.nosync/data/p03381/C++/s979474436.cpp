#include<iostream>
#include<iomanip>
//#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
int N;
ll X[2000000];

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> X[i];
	}

	vector<pair<ll, int> > vec;
	for(int i=0; i<N; i++){
		vec.push_back(make_pair(X[i], i));
	}
	sort(vec.begin(), vec.end());

	vector<pair<int, int> > vec2;
	for(int i=0; i<N; i++){
		vec2.push_back(make_pair(vec[i].second, i));
	}
	sort(vec2.begin(), vec2.end());

	for(int i=0; i<N; i++){
		int j=vec2[i].second;
		if(j<N/2){
			cout << vec[N/2].first << endl;
		}
		else{
			cout << vec[N/2-1].first << endl;
		}
	}

	return 0;
}
