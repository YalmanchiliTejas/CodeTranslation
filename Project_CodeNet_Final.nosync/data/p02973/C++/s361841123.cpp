#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007


int32_t main(){
    int n;cin>>n;
    int a[n];
    multiset<int> s;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    for(int i=0;i<n;i++){
    	if(s.empty()){
    		// c++;
    		s.insert(a[i]);
    		continue;
    	}
    	else{
    		auto it=s.lower_bound(a[i]);
    		if(it!=s.begin()){
    			it--;
    			s.erase(it);
    		}
    	}
    	s.insert(a[i]);
    }
    cout<<s.size()<<endl;
    
    
    return 0;
}