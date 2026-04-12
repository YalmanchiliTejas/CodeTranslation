#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;
#include<vector>
template<typename T>
void LIS(vector<T>& src,vector<T>& dst)
{
	dst.clear();

	for(auto&& i:src)
	{
		auto itr=upper_bound(dst.begin(),dst.end(),i);
		if(itr==dst.end())
			dst.push_back(i);
		else
			*itr=i;
	}

	return;
}

int main()
{
	int N;
	vector<int> A;

	cin >> N;
	for(int i=0;i<N;i++)
	{
		int a;
		cin >> a;
		A.push_back(-a);
	}

	vector<int> lis;
	LIS(A,lis);

	cout << lis.size() << endl;
	return 0;
}
