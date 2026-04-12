#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> vec,vec2;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		vec.push_back(x);
	}
	vec2 = vec;
	sort(vec.begin(),vec.end());

	int mid = n/2;
	int ans[n] = {0};
	for(int i=0;i<n;i++){
		int i_ = upper_bound(vec.begin(),vec.end(),vec2[i])-vec.begin();
		if(i_<= mid)
			printf("%d\n",vec[mid]);
		else
			printf("%d\n",vec[mid-1]);
	}
	return 0;
}