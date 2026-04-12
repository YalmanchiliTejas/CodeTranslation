#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP2(i,m,n) for(int i=m;i<n;i++)
int main(){
	int N;
	cin >> N;
	int H[N];
	REP(i,N){
		cin >> H[i];
	}
	int max = H[0];
	int ans = 1;
	REP2(i,1,N){
		if(H[i] >= max){
			++ans;
			max = H[i];
			//cout << i << ' ' << H[i] << endl;
		}
	}
	cout << ans << endl;
	return 0;
}