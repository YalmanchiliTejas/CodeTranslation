#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

vector<pint> go;

int main() {
	int n;
	while(n=in()){
		go.clear();
		int i,next;
		for(i=0;i<n;i++){
			next=in();
			if(i%2==1&&go[go.size()-1].first!=next){
				if(go.size()==1){
					go[0].first=next;
				}else{
					go[go.size()-2].second+=go[go.size()-1].second;
					go.pop_back();
				}
			}
			if(go.size()==0||go[go.size()-1].first!=next){
				pint buf;
				buf.first=next;
				buf.second=1;
				go.push_back(buf);
			} 
			else go[go.size()-1].second++;
//int j;
//for(j=0;j<go.size();j++)cout<<go[j].first<<" "<<go[j].second<<endl;
//cout<<endl;
		}
		int res=0;
		for(i=0;i<go.size();i++){
			if(go[i].first==0)res+=go[i].second;
		}
		cout<<res<<endl;
	}
	return 0;
}