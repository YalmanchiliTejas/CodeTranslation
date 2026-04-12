#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	cin>>n;
	vector<string> S(n);
	for(int i=0;i<n;i++){
		cin>>S[i];
		sort(S[i].begin(), S[i].end());
	}
	vector<int> Alpha(26,0);
	for(int i=0;i<S[0].length();i++){
		Alpha[S[0][i]-'a']++;
	}

	for(int i=1; i<n; i++){
		vector<int> Beta(26,0);
		for(int j=0; j<S[i].length(); j++){
			Beta[S[i][j]-'a']++;
		}

		for(int j=0;j<26;j++){
			Alpha[j]=min(Alpha[j],Beta[j]);
		}
	}

//	for(int i=0;i<26;i++){
//		if(Alpha[i]){
//			printf("%c:%d\n",i+'a',Alpha[i]);
//		}
//	}
	string ans="";
	for(int i=0;i<26;i++){
		for(int j=0;j<Alpha[i];j++){
			ans.push_back('a'+i);
		}
	}

	cout<<ans<<endl;

	return 0;
}
