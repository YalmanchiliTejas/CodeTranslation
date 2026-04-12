#include <bits/stdc++.h>
using namespace std;
#define sort(vec) sort(vec.begin(),vec.end())
#define reverse(vec) reverse(vec.begin(),vec.end())
#define unsort(vec); sort(vec);reverse(vec);
#define int long long
long long ans;

int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}

int lcm(int x,int y){
	return x*y/gcd(x,y);
}
 
signed main(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)cin>>s[i];
	int cnt[30],mi[30];
	for(int i=0;i<26;i++)mi[i]=114514;
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++)cnt[j]=0;
		for(int j=0;j<s[i].size();j++){
			cnt[s[i][j]-'a']++;
		}
		for(int j=0;j<26;j++){
			mi[j]=min(mi[j],cnt[j]);
		}
	}
	for(int i=0;i<26;i++){
		char z='a'+i;
		for(int j=0;j<mi[i];j++){
				cout<<z;
		}
	}
	cout<<endl;
}
