#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int, P> PP;

int n,m;
vector<int> e[10];
int a[10];

int main()
{
	cin>>n>>m;
	int ai,bi;
	for(int i=0;i<m;i++){
		cin>>ai>>bi;
		ai--; bi--;
		e[ai].push_back(bi);
		e[bi].push_back(ai);
	}
	a[0]=0;
	for(int i=1;i<n;i++){
		a[i]=i;
	}

	int ans=0;

	do{
		int ope=0;
		for(int i=1;i<n;i++){
			int s=a[i-1],t=a[i];
			int jope=0;
			for(int j=0;j<e[s].size();j++){
				if(e[s][j]==t){
					jope++; break;
				}
			}
			if(jope==0){
				ope++;
				break;
			}
		}
		if(ope==0)ans++;

	}while(next_permutation(a+1,a+n));

	cout<<ans<<endl;

	return 0;
}