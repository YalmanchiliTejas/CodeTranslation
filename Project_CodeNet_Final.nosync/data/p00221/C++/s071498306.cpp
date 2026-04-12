#include<cstdio>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<complex>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<=k;i++)
#define in(i,j,k) ((i)>=(j)&&(i)<=(k))
#define INF (1<<28)
#define pb(i) push_back(i)
#define fs first
#define sc second

const char dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int main(){
	int m,n;
	while(cin >> m >> n){
		if(!m)break;
		vector<int> v(m);
		rep(i,m)v[i]=i+1;
		int cnt = 0;
		reps(i,1,n){
			string s;
			cin >> s;
			if(v.size()==1)continue;
			char tmp[128];
			sprintf(tmp,i%15?i%5?i%3?"%d":"Fizz":"Buzz":"FizzBuzz",i);
			if(strcmp(tmp,s.c_str())!=0){
				std::vector<int>::iterator it = v.begin()+cnt;
				v.erase(it);cnt--;
//		rep(i,v.size())printf("%d%c",v[i],i==v.size()-1?'\n':' ');
			}
			cnt = (cnt+1)%v.size();
		}
		rep(i,v.size())printf("%d%c",v[i],i==v.size()-1?'\n':' ');
	}	
	return 0;
}