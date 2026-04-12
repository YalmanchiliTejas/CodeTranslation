#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	while(cin>>str,str!="#"){
		int ans=-1;
		for(int i=0,now=2,num=0;i<str.size();i++){
			if(str[i]-'a'>'g'-'a'&&str[i]-'a'<'q'-'a'||str[i]=='u'||str[i]=='y')num=1;
			else num=0;
			if(now!=1&&num==1){
				ans++;
				now=1;
			}
			else if(now!=0&&num==0){
				ans++;
				now=0;
			}
		}
		cout<<ans<<endl;
	}
}