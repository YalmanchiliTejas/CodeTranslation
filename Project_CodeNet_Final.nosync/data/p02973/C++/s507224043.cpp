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
#include<iomanip>
#include<set>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
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
	ll A[100001];
	set<ll> st;
	map<ll,int> stnum;
	scan(N);
	rep(i,N){
		scan(A[i]);
		A[i]=-A[i];
		auto itr=st.upper_bound(A[i]);
		if(itr!=st.end()){
			int num=(*itr);
			stnum[num]--;
			if(stnum[num]==0) st.erase(itr);
			if(st.count(A[i])){
				stnum[A[i]]++;
			}
			else{
				st.insert(A[i]);
				stnum[A[i]]=1;
			}
		}
		else{
			if(st.count(A[i])){
				stnum[A[i]]++;
			}
			else{
				st.insert(A[i]);
				stnum[A[i]]=1;
			}
		}
	}
	int ans=0;
	for(auto itr=st.begin();itr!=st.end();itr++){
		ans+=stnum[(*itr)];
	}
	prin(ans);
	return 0;
}
