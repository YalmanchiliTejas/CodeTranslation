#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define PRINT(str) printf(#str "\n")
#define yOUT PRINT(Yes)
#define nOUT PRINT(No)
#define YOUT PRINT(YES)
#define NOUT PRINT(NO)
 
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

int main(){
    int n, inp, max, cnt = 1;
	cin >> n >> max;
	REP(i, n-1){
		cin >> inp;
		if(max <= inp){
			cnt++;
			max = inp;
		}
	}

	cout << cnt << endl;

}
