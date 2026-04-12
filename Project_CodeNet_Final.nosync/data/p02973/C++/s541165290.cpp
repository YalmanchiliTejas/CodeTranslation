//abc134.cpp
//Sat Oct 12 12:39:21 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n];
	vector<int> heads;
	for (int i=0;i<n;i++){
		int a;
		cin >> a;
		if (heads.size()==0){
			heads.push_back(a);
		}else{
			if (a<=heads[0]){
				heads.insert(heads.begin(),a);
			}else {
				auto iter = lower_bound(heads.begin(),heads.end(),a);
				heads[iter-heads.begin()-1] = a;
			}
		}
	}

	cout << heads.size()<< endl;
//	printf("%.4f\n",ans);
}