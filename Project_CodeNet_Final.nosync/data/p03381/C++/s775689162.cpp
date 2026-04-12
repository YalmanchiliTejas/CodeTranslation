#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int LL;
vector<pair<int,int> > v1;
int s[200005];

int main(){
	int n;
	int a,b,c;
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(make_pair(a,i));
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<n;i++){
		if(i<n/2)a=n/2;
		else a=n/2-1;
		s[v1[i].second]=v1[a].first;
	}
	for(i=0;i<n;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
	
