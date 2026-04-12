#include<bits/stdc++.h>
using namespace std;
string s[8];

void fail(){
	cout<<"Impossible"<<endl;
	exit(0);
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(i==0&&j==0){
				if(s[i][j]!='#')
					fail();
				int cnt=0;
				cnt+=s[i+1][j]=='#';
				cnt+=s[i][j+1]=='#';
				if(cnt!=1)
					fail();
			}
			else if(i==n-1&&j==m-1){
				if(s[i][j]!='#')
					fail();
				int cnt=0;
				cnt+=s[i-1][j]=='#';
				cnt+=s[i][j-1]=='#';
				if(cnt!=1)
					fail();
			}
			else if (s[i][j]=='#'){
				int cnt=0;
				if(i>0)
					cnt+=s[i-1][j]=='#';
				if(j>0)
					cnt+=s[i][j-1]=='#';
				if(cnt!=1)
					fail();
				cnt=0;
				if(i<n-1)
					cnt+=s[i+1][j]=='#';
				if(j<m-1)
					cnt+=s[i][j+1]=='#';
				if(cnt!=1)
					fail();
			}
		}
	cout<<"Possible"<<endl;
}
