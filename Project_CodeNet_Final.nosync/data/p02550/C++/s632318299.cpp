#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <fstream>
using namespace std;
long long mod=998244353;
int main(){
	long long n,x,m;
	cin>>n>>x>>m;
	long long a=x;
	set<long long> hoge;
	vector<long long> au;
	for(int i=0;i<n&&hoge.find(a)==hoge.end();i++){
		hoge.insert(a);
		au.push_back(a);
		a*=a;
		a%=m;
	}
	long long ans=0;
	if(au.size()==n){
		for(int i=0;i<n;i++){
			ans+=au[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	long long mem;
	for(int i=0;i<au.size();i++){
		if(au[i]==a){
			mem=i;
			break;
		}
	}
	for(int i=0;i<mem;i++){
		ans+=au[i];
	}
	long long sum=0;
	for(int i=mem;i<au.size();i++){
		sum+=au[i];
	}
	n-=mem;
	for(int i=0;i<n%(au.size()-mem);i++){
		ans+=au[i+mem];
	}
	ans+=sum*(n/(au.size()-mem));
	cout<<ans<<endl;
	return 0;
}
