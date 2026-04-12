#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define DEKAI 1000000007
#define INF (1<<28)
#define FDBST int hogehogehoge;cin>>hogehogehoge;

int main(){
	string s;
	cin>>s;
	int ans=0;
	for(int i=1;i<s.size()-2;i++){
		if(i!=1&&s[0]=='0') continue;
		for(int j=i+1;j<s.size()-1;j++){
			if(j-i!=1&&s[i]=='0') continue;
			for(int k=j+1;k<s.size();k++){
				if(k-j!=1&&s[j]=='0') continue;
				if(k!=s.size()-1&&s[k]=='0') continue;
				int hoge1=0;
				for(int l=0;l<i;l++){
					hoge1*=10;
					hoge1+=s[l]-'0';
				}
				if(hoge1>255) continue;
				int hoge2=0;
				for(int l=i;l<j;l++){
					hoge2*=10;
					hoge2+=s[l]-'0';
				}
				if(hoge2>255) continue;
				int hoge3=0;
				for(int l=j;l<k;l++){
					hoge3*=10;
					hoge3+=s[l]-'0';
				}
				if(hoge3>255) continue;
				int hoge4=0;
				for(int l=k;l<s.size();l++){
					hoge4*=10;
					hoge4+=s[l]-'0';
				}
				if(hoge4>255) continue;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

