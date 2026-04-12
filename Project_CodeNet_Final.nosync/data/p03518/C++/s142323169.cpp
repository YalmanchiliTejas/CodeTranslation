#include<iostream>
#include<vector>
using namespace std;
const int N=202;
int ar[N];
vector<int> ans;
int main(){
	int n,i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	bool cac=true;
	while(cac){
		cac=false;
		for(i=1;i<=n;i++){
			ans.push_back(1);
			if(i<n&&ar[i]>ar[i+1]){
				ans.push_back(n-1);
				swap(ar[i],ar[i+1]);
				cac=true;
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<'\n';
	}
}