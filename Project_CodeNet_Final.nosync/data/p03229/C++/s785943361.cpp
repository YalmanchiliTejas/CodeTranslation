#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)

signed main(){

	lli n;
	cin>>n;
	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	sort(a.begin(),a.end());

	vector<lli> v;
	lli first = 1;
	v.push_back(a[0]);
	lli last = a.size()-1;

	while(first <= last){
		lli t1 = max(abs(a[first]-v[0]),abs(a[first]-v[v.size()-1]));
		lli t2 = max(abs(a[last]-v[0]),abs(a[last]-v[v.size()-1]));
		if(t1>t2){
			if(abs(a[first]-v[0])>abs(a[first]-v[v.size()-1])){
				auto itr = v.begin();
				v.insert(itr,a[first]);
			}
			else{
				v.push_back(a[first]);
			}
			first++;
		}
		else{
			if(abs(a[last]-v[0])>abs(a[last]-v[v.size()-1])){
				auto itr = v.begin();
				v.insert(itr,a[last]);
			}
			else{
				v.push_back(a[last]);
			}
			last--;
		}
	}

	lli sum=0;
	REP(i,1,v.size()){
		sum += abs(v[i]-v[i-1]);
	}
	cout<<sum<<endl;


	return 0;
}