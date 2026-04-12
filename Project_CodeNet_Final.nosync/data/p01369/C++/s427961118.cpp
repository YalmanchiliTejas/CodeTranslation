#include<string>
#include<iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	bool f[128]={};
	f['q']=f['w']=f['e']=f['r']=f['t']=f['a']=f['s']=f['d']=f['f']=f['g']=f['z']=f['x']=f['c']=f['v']=f['b']=true;

	for(string s;cin>>s,s!="#";){
		int len=s.length(),ans=0;
		rep(i,len) if(i>0 && f[s[i-1]]!=f[s[i]]) ans++;
		cout<<ans<<endl;
	}

	return 0;
}