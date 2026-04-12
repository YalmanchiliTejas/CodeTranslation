#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin>>n;

    vector<vector<int>> s(n,vector<int>(27));

    for(int i=0;i<n;i++){
    	string x;
    	cin>>x;
    	for (int j=0;j<(int)x.length();j++) s[i][x[j]-'a']++;
    }

	
	string res;
	for(int i=0;i<27;i++){
		int f = 1;
		int mn = INT_MAX;
		for(int st = 0;st<n;st++){
			if(s[st][i]){
				mn = min(mn,s[st][i]);
			} else f = 0;
		}
		if(f){
			for(int ab = 0;ab<mn;ab++) res+=(i+'a');
		}
	}

	cout<<res;

}