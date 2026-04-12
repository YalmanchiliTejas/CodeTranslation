#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;

	while(cin>>s){
		int ans=0;
		if(s=="#")break;

		int num[35]={0};
		
		string r="yuiophjklnm";

		for(int i=0;i<s.size();i++){
			for(int j=0;j<r.size();j++){
				if(s[i]==r[j]){
					num[i]=1;
					break;
				}
			}
		}

		for(int i=0;i<s.size()-1;i++){
			if(num[i]!=num[i+1])ans++;
		}
		cout<<ans<<endl;

	}

	return 0;
}