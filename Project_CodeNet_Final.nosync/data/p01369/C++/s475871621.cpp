#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	while(cin>>str,str!="#"){
		int ans=0;
		for(int i=0,now=-1,num=0;i<str.size();i++){
			if(str[i]>103&&str[i]<113||str[i]==117||str[i]==121)num=1;
			else num=0;
			if(now==-1)now=num;
			else if(now!=1&&num==1||now!=0&&num==0){
				ans++;
				now=(now+1)%2;
			}
		}
		cout<<ans<<endl;
	}
}