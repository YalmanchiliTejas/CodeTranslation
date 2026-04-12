#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
int main(void){
	int n;
	int box[100000];
	int i;
	int MAX;
	int sum;
	V v;
	cin>>n;
	MAX=-1;
	for(i=0;i<n;i++){
		cin>>box[i];
		MAX=max(MAX,box[i]);
	}
	for(i=1;i<=MAX;i++){
		if(MAX%i==0){
			v.push_back(i);
		}
	}
	sort(v.begin(),v.end());
	// for(auto it:v){
		// cout<<it<<endl;
	// }
	sum=0;
	for(i=0;i<n;i++){
		auto it1=lower_bound(v.begin(),v.end(),box[i]);
		//auto it2=upper_bound(v.begin(),v.end(),box[i]);
		//cout<<*it1<<endl;
		// cout<<*it2<<endl;
		sum+=*it1-box[i];
	}
	cout<<sum<<endl;
	return 0;
}
