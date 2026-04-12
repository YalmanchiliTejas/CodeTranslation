#include<bits/stdc++.h>
using namespace std;
#define int long long 
 
main(){
	int n,x,m; cin>>n>>x>>m;
	
	vector<int> v;
	vector<int> rep;
	vector<bool> visit(m + 1);
	int cnt=1, curr=x, ans=0;
	
	while(cnt <= n){
		if(!visit[curr]){
			visit[curr] = 1;
			ans += curr;
			v.push_back(curr);
			curr = (curr * curr) % m;
		}
		else{
			while(v.back()!=curr){
	            rep.push_back(v.back());
                v.pop_back();				
			}
			rep.push_back(v.back());
			break;
		}
		cnt++;
	}
	cnt--;
 	reverse(rep.begin(), rep.end());
	
	int rem_n = n-cnt;
	if(rem_n > 0){
		int cyclen = rep.size();
	    int times = rem_n / cyclen;
	    int rem = rem_n % cyclen;
	
	    for(int i=0; i<cyclen; i++){
		    ans += rep[i] * times;
		    if(i < rem) ans += rep[i];
		}
	}
	cout<<ans;
}