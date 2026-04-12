#include<iostream>

using namespace::std;
string s;
int n,t;

void brute(int i,string g,int k){
	if(k==0){
		if(g>s)
			return;
		//cout<<g<<' '<<(g>s)<<'\n';
		int o=1;
		//for(int j=0;j<n;j++)
		//	o*=max(1,g[j]-'0');
		t+=o;
		return;
	}
	//cout<<g<<'\n';
	for(;i<n-k+1;i++){
		if(k!=1)
			for(int j='1';j<='9' && g<=s;j++){
				g[i]=j;
				if(g<=s) brute(i+1,g,k-1);
			}
		else{
			g[i]='9';
			if(g>s)
				t+=s[i]-'0';
			else t+=9;
		}
		g[i]='0';
	}
}

int main(){
	cin>>s;
	int k;
	n=s.length();
	cin>>k;
	string g="";
	for(int i=0;i<n;i++)
		g+="0";
	brute(0,g,k);
	cout<<t<<'\n';
}
