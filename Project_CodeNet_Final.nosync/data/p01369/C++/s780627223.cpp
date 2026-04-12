#include<bits/stdc++.h>
using namespace std;

int main(){
	char left[]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
	string s;
	while(cin>>s, s!="#"){
		char prev,now;		int ans=0;

		prev=now='R';
		for(int j=0;j<15;j++){
			if(s[0]==left[j]){
				prev=now='L';
				break;
			}
		}

		for(int i=1;i<s.length();i++){
			for(int j=0;j<15;j++){
				if(s[i]==left[j]){
					now='L';
					break;
				}else now='R';
			}
			if(prev != now){
				ans++;
			}
			prev=now;
		}
		cout<<ans<<endl;
	}

	return 0;
}
