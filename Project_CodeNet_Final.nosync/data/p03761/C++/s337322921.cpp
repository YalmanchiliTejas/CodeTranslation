#include<iostream>
#include<cstring>
#include<string> 
#include<algorithm>
const int INF=0xfffff;
using namespace std;
int ans[30];
int num[30];
int main(){
	int n;
	string str;
	for(int i=0;i<30;i++)ans[i]=INF;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str;
		memset(num,0,sizeof(num));
		int len=str.length();
		for(int j=0;j<len;j++){
			num[str[j]-'a']++;
		}
		for(int i=0;i<26;i++){
			ans[i]=min(ans[i],num[i]);
		}
	}
	int flag=0;
	for(int i=0;i<26;i++){
		if(ans[i]!=0){
			flag=1;
			for(int j=0;j<ans[i];j++){
				cout<<char('a'+i);
			}
		}
	}
	if(flag==0)cout<<endl;
	return 0;
} 