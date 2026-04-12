#include<iostream>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;
#define INF INT_MAX
int n;
string ans;
int d[26];
int main(){
	for(int i=0;i<26;i++)d[i]=INF;
	cin>>n;
	for(int i=0;i<n;i++){
		string st;
		cin>>st;
		int nd[26]={};
		for(int j=0;j<st.size();j++){
			nd[st[j]-'a']++;
		}
		for(int j=0;j<26;j++){
			d[j]=min(d[j],nd[j]);
		}
	}
	for(int i=0;i<26;i++){
		if(d[i]==INF)continue;
		for(int j=0;j<d[i];j++)ans+=('a'+i);
	}
	cout<<ans<<endl;
	return 0;
}