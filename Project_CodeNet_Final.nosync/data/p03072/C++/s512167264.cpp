#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> vec(n, 0);
	for(int i = 0; i < n; ++i)cin>>vec[i];
	int x = vec[0];
	int res = 0;
	for(int i = 1; i < n; ++i){
		if(vec[i] >= x){
			res++;
			x = vec[i];
		}
	}
	cout<<res+1<<endl;   
	return 0;
}
