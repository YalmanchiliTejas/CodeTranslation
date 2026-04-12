#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define REP(i, n) FOR(i, 0, n)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
#define PB push_back
#define MP make_pair

int n;
#define N 112345
int a[N];
vi p;

int main(){
	scanf("%d", &n);
	REP(i, n) scanf("%d", a+i);
	int x=0;
	REP(i, n) LAR(x, a[i]);
	FOR(i, 1, x+1) if(x%i==0) p.PB(i);
	int ans=0;
    
	REP(i, n){
		REP(j, p.size()){
			int k=p[j];
			if(a[i]<=k){
				ans+=k-a[i];
				break;
			}
		}
	}
	printf("%d\n", ans);
}