#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <stack>
#include <list>
using namespace std;
#define INF 100000000
typedef long long int lli;
typedef pair<int,int> P;

int s[100001];

int main(){
	int n;
	while(cin>>n&&n){
		for(int i=0; i<n; ++i){
			cin >> s[i];
		}
		vector<P> t;
		t.push_back(P(s[0],1));
		for(int i=1; i<n; ++i){
			if((i+1)%2==0){
				if(t[t.size()-1].first!=s[i]){
					int sum=t[t.size()-1].second+1;
					t.pop_back();
					if(!(t.empty())) t[t.size()-1].second+=sum;
					else t.push_back(P(s[i],sum));
				} else{
					++t[t.size()-1].second;
				}
			} else {
				if(t[t.size()-1].first==s[i]){
					++t[t.size()-1].second;
				} else {
					t.push_back(P(s[i],1));
				}
			}
		}
		int ans=0;
		for(int i=0; i<t.size(); ++i){
			if(t[i].first==0) ans+=t[i].second;
		}
		cout << ans << "\n";
	}
	return 0;
}