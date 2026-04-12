#include <bits/stdc++.h>
using namespace std;

vector<int64_t> suffixSum(vector<int64_t> &vct){
	vector<int64_t> suffixSumVct(vct.size(), 0);
	for(int i=vct.size()-1;i>=0;i--){
		if(i==vct.size()-1)
			suffixSumVct[i] = 0;
		else{
			suffixSumVct[i] = vct[i+1] + suffixSumVct[i+1];
		}
	}
	return suffixSumVct;
}

int main(){
	int64_t N,tmp;
	vector<int64_t> vct;

	cin >> N;
	vct.resize(N, 0);
	for (int i=0;i<N;i++){
		cin >> tmp;
		vct[i] = tmp;
	}

	vector<int64_t> suffixSumVct = suffixSum(vct);
	int64_t res = 0;
	for (int i=0;i<vct.size();i++)
		res = ((res%1000000007) + ((vct[i]%1000000007) * (suffixSumVct[i]%1000000007)))%1000000007;

	cout << res << "\n";
	return 0;
}