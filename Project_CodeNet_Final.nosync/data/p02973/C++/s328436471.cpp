#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	multiset<int>s;
	multiset<int>::iterator it;
	for(int i=0; i<n; i++){
		if(s.empty()) s.insert(arr[i]);
		else{
			it = s.lower_bound(arr[i]);
			if(it==s.begin()) s.insert(arr[i]);
			else{
				it--;
				s.erase(it);
				s.insert(arr[i]);
			}
		}
	}
	cout<<s.size();
}