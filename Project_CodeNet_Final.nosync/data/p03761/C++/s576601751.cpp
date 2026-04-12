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
	string S[50];
	int alphamin[26];
	rep(i,26) alphamin[i]=INF;
	vector<string> Sbubun;
	scan(N);
	rep(i,N){
		scan(S[i]);
		int alpha[26]={0};
		rep(j,S[i].size()){
			alpha[S[i][j]-'a']++;
		}
		rep(j,26){
			alphamin[j]=min(alphamin[j],alpha[j]);
		}
	}
	rep(i,26){
		rep(j,alphamin[i]){
			printf("%c",'a'+i);
		}
	}
	kaigyo;
	return 0;
}
