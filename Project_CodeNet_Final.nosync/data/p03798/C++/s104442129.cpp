#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N;
	string s;
	scan(N);
	scan(s);
	rep(i,4){
		char kind[100000];
		if(i==0) kind[0]='S',kind[1]='S';
		else if(i==1) kind[0]='S',kind[1]='W';
		else if(i==2) kind[0]='W',kind[1]='S';
		else if(i==3) kind[0]='W',kind[1]='W';
		int consistent;
		for(int j=1;j<=N-2;j++){
			if((kind[j]=='S')^(s[j]=='o')) kind[j+1]=(kind[j-1]=='S' ? 'W' : 'S');
			else kind[j+1]=kind[j-1];
		}
		if(((kind[0]=='S')^(s[0]=='o')^(kind[1]==kind[N-1]))&&((kind[N-1]=='S')^(s[N-1]=='o')^(kind[N-2]==kind[0]))){
			consistent=1;
		}
		else{
			consistent=0;
		}
		if(consistent){
			rep(j,N) printf("%c",kind[j]);
			kaigyo;
			return 0;
		}
		else continue;
	}
	prin(-1);
	return 0;
}
