#include<iostream>
#include<vector>

using namespace std;

int main(void){
	int n,i,j;
	vector<int> v;
	int ans=0;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>j;
		v.push_back(j);
	}
	j=0;
	for(i=0;i<n;i++){
		if(j<=v[i]){
			ans++;
			j=v[i];
		}
		
	}
	cout<<ans<<endl;
	
	
	
	return 0;
	
	
}