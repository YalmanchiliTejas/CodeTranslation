#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	priority_queue<long long> num;

	for(int i=0;i<n;i++){
		long long ho;
		cin>>ho;
		num.push(ho);
	}

	vector<long long> v1;
	vector<long long> v2;

	bool high=true;

	for(int i=0;i<n;i++){
		long long minu=1;
		if(high==false) minu=-1;

		if(i==0 || i==n-1){
			v1.push_back(minu);
			v2.push_back(minu*-1);
		}else{
			v1.push_back(minu*2);
			v2.push_back(minu*2*-1);
		}cerr<<v1.at(i)<<" "<<v2.at(i)<<endl;

		high=!high;
	}

	sort(v1.begin(),v1.end(),greater<long long>());
	sort(v2.begin(),v2.end(),greater<long long>());

	long long ans1=0;
	long long ans2=0;

	for(int i=0;i<n;i++){
		ans1+=v1.at(i)*num.top();
		ans2+=v2.at(i)*num.top();
		num.pop();
	}

	cout<<max(ans1,ans2)<<endl;

	return 0;
}
