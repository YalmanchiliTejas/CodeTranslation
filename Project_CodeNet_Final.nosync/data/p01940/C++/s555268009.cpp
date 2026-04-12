#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;



int main()
{
	string A,B;cin>>A>>B;
	
	vector<vector<int>>places(26);
	for (int i = 0; i < A.size(); ++i) {
		places[A[i]-'a'].push_back(i);
	}

	vector<int>v;
	{
		 int now=-1;
		for (int i = 0; i < B.size(); ++i) {
			int ch(B[i]-'a');

			auto it=upper_bound(places[ch].begin(),places[ch].end(),now);
			if (it == places[ch].end()) {
				v.clear();
				break;
			}
			else {
				v.push_back(*it);
				now=*it;
			}
		}
	}
	if (v.empty()) {
		cout<<"no"<<endl;
	}
	else {
		bool ok = true;
		int N=B.size();
		for (int i = 0; i < B.size(); ++i) {
			int pre=i==0?0:v[i-1]+1;
			int nex=i==N-1?A.size()-1:v[i+1]-1;

			{
				auto lt=lower_bound(places[B[i]-'a'].begin(),places[B[i]-'a'].end(),pre);
				auto rt=upper_bound(places[B[i]-'a'].begin(),places[B[i]-'a'].end(),v[i]-1);

				if(lt!=rt)ok=false;
			}
			{
				auto lt = lower_bound(places[B[i] - 'a'].begin(), places[B[i] - 'a'].end(), v[i]+1);
				auto rt = upper_bound(places[B[i] - 'a'].begin(), places[B[i] - 'a'].end(), nex);

				if (lt != rt)ok = false;
			}
		}
		if(ok)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	
	return 0;
}

