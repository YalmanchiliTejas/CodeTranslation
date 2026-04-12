#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define IN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef long long ll;
/////////////////////////(๑•﹏•๑｀)/////////////////////////
int n,q;
int a[100002];

int binary_search(int key){
	// <= left never satisfy
	// right <= always satisfy

	int left = -1; 
	int right = n; // index of size + 1;

	while(right - left > 1){
			int mid = left + (right - left) / 2;

			if (a[mid] >= key) right = mid;
			else left = mid;
	}

	// left is the maximum that don't satisfy the condition.
	// right is the minimum that satisfies the condtion.

	return right; 

}

int main(){
	SCD(n);
	REP(i,n){
		int x; SCD(x);
		a[i] = x;
	}
	SCD(q);

	REP(i,q){
		int k; SCD(k);
		PRINTD(binary_search(k));
	}
	return 0;
}
	
	

