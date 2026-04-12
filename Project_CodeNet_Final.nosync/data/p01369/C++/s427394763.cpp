#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string s="yuiophjklnm";
	
	while(1){
		
		string a;
		
		cin >> a;
		
		if(a=="#") break;
		
		bool left=true;
		for(int i=0;s[i];i++){
			if(s[i]==a[0]){
				left=false;
			}
		}
		int cnt=0;
		
		for(int i=1;a[i];i++){
			bool be=left;
			for(int j=0;s[j];j++){
				left=true;
				if(s[j]==a[i]){
					left=false;
					break;
				}
			}
			if(be!=left){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}
