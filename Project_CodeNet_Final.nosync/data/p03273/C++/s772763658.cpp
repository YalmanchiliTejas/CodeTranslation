#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
#define Fm(i) for(int i=0;i<m;i++)
bool ok[1010]={false},ok2[1010]={false};
char c[111][111];
int main(){
	int n,m;
	cin>>n>>m;
	F(i)Fm(j)cin>>c[i][j];
	F(i)Fm(j)ok[i]|=c[i][j]=='#';
	Fm(i)F(j)ok2[i]|=c[j][i]=='#';
	F(i){
		Fm(j)if(ok[i]&&ok2[j])cout<<c[i][j];
		if(ok[i])cout<<endl;
	}
	return 0;
}
