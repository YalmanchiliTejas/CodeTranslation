#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
int main(){
	int n;
	vector<int> x,y;
	cin>>n;
	for(int i=0; i<n; i++){
		int t;
		cin>>t;
		x.push_back(t);
		y.push_back(t);
	}
	sort(y.begin(),y.end());
	int small = y[n/2 - 1];
	int big = y[n/2];
	for(int i=0;i<n;i++){
		if(x[i]<=small){
			cout<<big<<endl;
		}
		else{
			cout<<small<<endl;
		}
	}
	return 0;
}