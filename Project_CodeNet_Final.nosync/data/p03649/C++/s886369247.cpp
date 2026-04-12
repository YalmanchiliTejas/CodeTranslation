#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include <map>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"time.h"
using namespace std;

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define dump(x)  cerr << #x << " = " << (x) << endl

//毎回変える場所
#define N_MAX 200001
#define INF 1000000007

//問題文のとおり
char temp[50];
LL N, K;
LL a[50];

//関数
bool end(LL* b){
	REP(i, N) {
		if(b[i]>=N)return false;
	}
	return true;
}
bool allBig(LL* b) {
	REP(i, N) {
		if(b[i]<N)return false;
	}
	return true;
}

bool min(LL* b) {
	LL ans=b[0];
	REP(i, N) {
		if(a[i]<ans)ans=a[i];
	}
	return ans;
}

int main() {
	cin>>N;
	REP(i,N)cin>>a[i];

	//1回の操作で、数列全体で見れば-1されている。
	//そこで、溢れている数値を-1する
	//⇔操作を1回する　と考える。

	while (end(a) == false) {
		//全部が溢れているとき、一気に消す
		
		LL mini=min(a);
		if (mini >= N) {
			mini-=N;
			REP(i,N)a[i]-=mini;
			K+=mini*N;
		}

		REP(i, N) {
			//溢れている奴に対して適用
			if (a[i] >= N) {

				//消す回数
				LL delNum=a[i]/N;
				a[i]%=N;
				K+=delNum;

				//逆に増やす
				REP(j, N) {
					if(i!=j)a[j]+=delNum;
				}
			}
		}
	}


	cout<<K<<endl;
	//cin>>temp;

	return 0;
}