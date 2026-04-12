#include<bits/stdc++.h>

using namespace std;

int n, ind[30] = {0}, x, mn[30] = {0};

int main(){
	string s, out;
	
	
	cin>>n;
	
	cin>>s;
	for(int j=0; j<s.length(); j++){
		x = s[j] - 'a';
		ind[x]++;
		mn[x] = ind[x];
	}
	
	for(int i=1; i<n; i++){
		cin>>s;
		memset(ind, 0, sizeof(ind));

		for(int j=0; j<s.length(); j++){
			x = s[j] - 'a';
			ind[x]++;
		}
		
		for(int j=0; j<27; j++){
			if(mn[j]>ind[j]) mn[j] = ind[j];
		}
	}
	
	for(int i=0; i<27; i++){
		for(int j=0; j<mn[i]; j++){
			out = 'a' +i;
			cout<<out;
		}
	}
		
	
	
		
		
	return 0;
}