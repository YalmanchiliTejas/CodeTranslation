/* 
	Author: ankrypt
*/


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
  
ll N;
vector<ll> vals;
ll val;
  
int main() {
	scanf("%lld", &N);
	for(ll i = 0; i < N; i++) {
		scanf("%lld", &val);
		vals.push_back(val);
	}
	sort(vals.begin(),vals.end());
	int l = vals[vals.size()-1]; 
	int r = l;             
	int i = 0,j = vals.size()-2;
	long long int sum=0;
	while(i < j){
	        int li = abs(l-vals[i]);
	        int ri = abs(r-vals[i]);
	        int lj = abs(l-vals[j]);
	        int rj = abs(r-vals[j]);
	        if(li > ri || lj > rj) { 
	                if(li > lj){
	                        sum+=li;
	                        l=vals[i++];
	                }
	                else {
	                        sum += lj;
	                        l = vals[j--];
	                }
	        }else{
	                if(ri > rj){
	                        sum += ri;
	                        r = vals[i++];
	                }
	                else{
	                        sum += rj;
	                        r = vals[j--];
	                }
	        }
	}
	sum += max(abs(l - vals[i]), abs(r - vals[i]));
	cout<< sum << endl;
	return 0;
}
/*
	Powered by Buggy Plugin
*/
