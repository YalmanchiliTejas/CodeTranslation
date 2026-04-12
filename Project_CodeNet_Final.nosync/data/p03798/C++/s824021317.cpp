#include<iostream>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include <cstdlib>
#include<algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
const long long INF=10000000000000LL;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,M,K=1,C;
ll A,B,W;
ll T,a,b;
double v[55],D[55];
ll ans=0;
int l;
bool h;
//bool D[100005];
ll S[50][50]={};
char str1[100005],str2[4][100005];
map<string,int> m;

int main(){
	cin>>N;
	str2[0][0]='S';
	str2[0][1]='S';
	str2[1][0]='S';
	str2[1][1]='W';
	str2[2][0]='W';
	str2[2][1]='S';
	str2[3][0]='W';
	str2[3][1]='W';
	for(int i=0;i<N;++i){
		cin>>str1[i];
	}
	str1[N]=str1[0];
	for(int i=0;i<4;++i){
		l=0;
		for(int j=1;j<N+1;++j){
			if(str2[i][j]=='S'){
				if(str1[j]=='o')str2[i][j+1]=str2[i][j-1];
				if(str1[j]=='x'&&str2[i][j-1]=='S')str2[i][j+1]='W';
				if(str1[j]=='x'&&str2[i][j-1]=='W')str2[i][j+1]='S';
			}
			if(str2[i][j]=='W'){
				if(str1[j]=='x')str2[i][j+1]=str2[i][j-1];
				if(str1[j]=='o'&&str2[i][j-1]=='S')str2[i][j+1]='W';
				if(str1[j]=='o'&&str2[i][j-1]=='W')str2[i][j+1]='S';
			}

		}
		//for(int j=0;j<N+2;++j)cout<<str2[i][j];
		//cout<<endl;
		if(str2[i][0]==str2[i][N]&&str2[i][1]==str2[i][N+1]){
			for(int j=0;j<N;++j)cout<<str2[i][j];
			cout<<endl;
			h=true;
			break;
		}
	}
	if(!h)cout<<-1<<endl;
	return 0;
}
