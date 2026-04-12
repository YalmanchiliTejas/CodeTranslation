#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	vector<long long int> v;
	while(n--){
		long long int h;
		cin>>h;
		v.push_back(h);
	}
	vector<long long int> minn;
	minn.push_back(0);
	minn.push_back(v[0]);
	for(long long int i=1;i<v.size();i++){
		minn.push_back(max(v[i],minn[i]));
	}
	long long int c=0;
	for(long long int i=1;i<v.size();i++){
		if(v[i]>=minn[i]){
			c++;
		}
	}
	cout<<c+1;
	return 0;
}