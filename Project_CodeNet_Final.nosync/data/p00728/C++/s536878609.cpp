#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int tem;
	int sum;


	while(1){
		cin>>n;
		if(n==0) break;

		sum=0;
		vector<int> v;
		for(int i1=0; i1<n; i1++){
			cin>>tem;
			v.push_back(tem);
			sum+=tem;
		}
		sort(v.begin(), v.end());
		sum-=(v[0]+v[v.size()-1]);
		cout<<sum/(n-2)<<endl;
		
	}

	return 0;
}