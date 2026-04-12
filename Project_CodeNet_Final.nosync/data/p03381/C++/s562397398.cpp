#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define lli long long int

using namespace std;

int main(){

	lli n;
	vector<lli> x;
	vector<lli> y;

	cin>>n;

	for(int i=0;i<n;i++){
		lli tmp;
		cin>>tmp;
		x.push_back(tmp);
		y.push_back(tmp);
	}
	sort(x.begin(),x.end());

	lli a = x.at(n/2-1);
	lli b = x.at(n/2);

	for(int i=0;i<n;i++){
		lli now = y.at(i);
		if(now<=a){
			cout<<b<<endl;
		}
		else{
			cout<<a<<endl;
		}
	}

	return 0;

}