#include <iostream>
#include <iomanip>
#include <vector>
#define ALL(a)  (a).begin(),(a).end()

//REPEAT
//------------------------------------------
#define FOR(i,m,n) for(int (i)=(m);(i)<(n); i++)
#define REP(i, n) for(int (i)=0;(i)<(n);(i)++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define WREP(i,in,j,jn) REP(i,in)REP(j,jn)
using namespace std;
//-------------------------------------------

int main(void){
	int x,y;
	cin>>x>>y;
	cout<<(x==y?"Yes":"No");
	return 0;
}
