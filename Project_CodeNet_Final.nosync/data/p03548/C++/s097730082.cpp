#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
#define SORT(c) sort((c).begin(),(c).end())
#define MOD 1000000007
//S.size()
//配列名.Length()

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<bool> VB;
typedef unsigned long long ll;

int main(void){
	int X,Y,Z;cin>>X>>Y>>Z;
	int wa = 0;
	int cnt = 0;
	while (wa + Z <= X) {
		wa += Y + Z;
		cnt++;
	}
	cout<<cnt - 1;
}
