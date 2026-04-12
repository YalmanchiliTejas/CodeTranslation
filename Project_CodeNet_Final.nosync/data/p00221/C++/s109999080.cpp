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

int p[1010];
string str;
stringstream ss;
int m,n;
bool one;

void clear(int k){
	if(one)return;
	else p[k]=0;
}

int next(int k){
	k++;
	while(1){
		if(k>m)k=1;
		if(p[k]==1)break;
		k++;
	}
	return k;
}

int main() {
	while(cin>>m>>n,m){
		one=false;
		int i,j,k;
		k=1;
		for(i=1;i<=m;i++)p[i]=1;
		for(i=1;i<=n;i++){
			int count=0;
			for(j=1;j<=m;j++){
				if(p[j])count++;
			}
			if(count==1)one=true;
			cin>>str;
			if(i%15==0){
				if(str!="FizzBuzz"){
					clear(k);
				}
				k=next(k);
			}else if(i%3==0){
				if(str!="Fizz"){
					clear(k);
				}
				k=next(k);
			}else if(i%5==0){
				if(str!="Buzz"){
					clear(k);
				}
				k=next(k);
			}else{
				int x;
				for(j=0;j<str.size();j++){
					if(str[j]<'0'||'9'<str[j]){
						break;
					}
				}
				if(j!=str.size()){
					clear(k);
				}else{
					x=0;
					for(j=0;j<str.size();j++){
						x=x*10+str[j]-'0';
					}
					if(i!=x)clear(k);
				}
				k=next(k);
			}
		}
		bool first=true;
		for(i=1;i<=m;i++){
			if(p[i]==1){
				if(first){
					cout<<i;
					first=false;
				}else{
					cout<<" "<<i;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}