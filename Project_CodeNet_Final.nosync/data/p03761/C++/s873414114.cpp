#include<bits/stdc++.h>
#include <math.h>
#include <cmath>
#include <limits>
#include <iostream>
#include <assert.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=10000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	int x,y,cost;
};
int main(){

	string s2[27]={};
	string s3[27]={};
	string ans={};
	int n;
	cin>>n;
	rep(i,26){
		s3[i]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	}
	rep(j,n){
		string s;
		cin>>s;
		rep(i,s.size()){
			if(s[i]=='a')s2[0]+='a';
			if(s[i]=='b')s2[1]+='b';
			if(s[i]=='c')s2[2]+='c';
			if(s[i]=='d')s2[3]+='d';
			if(s[i]=='e')s2[4]+='e';
			if(s[i]=='f')s2[5]+='f';
			if(s[i]=='g')s2[6]+='g';
			if(s[i]=='h')s2[7]+='h';
			if(s[i]=='i')s2[8]+='i';
			if(s[i]=='j')s2[9]+='j';
			if(s[i]=='k')s2[10]+='k';
			if(s[i]=='l')s2[11]+='l';
			if(s[i]=='m')s2[12]+='m';
			if(s[i]=='n')s2[13]+='n';
			if(s[i]=='o')s2[14]+='o';
			if(s[i]=='p')s2[15]+='p';
			if(s[i]=='q')s2[16]+='q';
			if(s[i]=='r')s2[17]+='r';
			if(s[i]=='s')s2[18]+='s';
			if(s[i]=='t')s2[19]+='t';
			if(s[i]=='u')s2[20]+='u';
			if(s[i]=='v')s2[21]+='v';
			if(s[i]=='w')s2[22]+='w';
			if(s[i]=='x')s2[23]+='x';
			if(s[i]=='y')s2[24]+='y';
			if(s[i]=='z')s2[25]+='z';
		}
		rep(i,26){
			if(s2[i].size()<s3[i].size())s3[i]=s2[i];
			s2[i]={};
		}
	}
	rep(i,26)ans+=s3[i];
	cout<<ans<<endl;
	return 0;

}


