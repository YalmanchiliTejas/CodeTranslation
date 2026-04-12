#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

vector<int> G[100005];
int used[100005];
bool ans;

bool search(int s, int tama){
	vector<int> children;
	used[s]=true;
	rep(i,G[s].size()){
		if(!used[G[s][i]]){
			children.push_back(G[s][i]);
		}
	}
	if(children.size() == 0){
		if(tama%2==0){
			//cout<<s<<"a"<<endl;
			return true;
		}
	}
	if(children.size()==1){
		//cout<<s<<"b"<<endl;
		return search(children[0],tama+1);
	}
	int count=0;
	rep(i,children.size()){
		if(search(children[i],0)){
			count++;
		}
	}
	if(count >= 2){
		//cout<<s<<"c"<<endl;
		ans=true;
		return true;
	}
	if(count==1 && tama%2 == 1){
		//cout<<s<<"d"<<endl;
		return true;
	}
	if(count == 0 && tama%2 == 0){
		return true;
	}
	//cout<<s<<"e"<<endl;
	return false;
}

int main(void){
	int n,a,b;
	cin>>n;
	rep(i,n-1){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	//cout<<"First"<<endl;
	//return 0;
	reps(i,n){
		used[i]=false;
	}
	ans = false;

	if(n%2==1){
		cout<<"First"<<endl;
		return 0;
	}
	bool memo = search(1,0);
	if(memo || ans){
		cout<<"First"<<endl;
	}else{
		cout<<"Second"<<endl;
	}
	return 0;
}
