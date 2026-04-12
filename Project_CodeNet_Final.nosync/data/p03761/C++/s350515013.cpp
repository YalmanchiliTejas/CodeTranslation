#include<iostream>
#include<string>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n;
	cin>>n;
	string s[n];
	rep(i,n){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
	}
	string ans="";
	rep(i,26){
		int num=100;
		rep(j,n){
			int tmp=0;
			rep(k,s[j].size())if(s[j][k]==(char)('a'+i))tmp++;
			num=min(num,tmp);
		}
		rep(j,num)ans+=(char)('a'+i);
	}
	cout<<ans<<endl;
	return 0;
}