#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef long long ll;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };

int main(){
	ios::sync_with_stdio(false);

	int n;

	while(1){
		scanf("%d", &n);
		if(n==0)	break;

		int Dice[3]={1, 2, 3};
		char str[10];
		int sum=1;

		while(n--){
			scanf("%s", str);
			int temp = Dice[0];

			switch (str[0]) {
				case 'N':{
					Dice[0]=Dice[1];
					Dice[1]=7-temp;
					break;
				}
				case 'S':{
					Dice[0]=7-Dice[1];
					Dice[1]=temp;
					break;
				}
				case 'E':{
					Dice[0]=7- Dice[2];
					Dice[2]=temp;
					break;
				}
				case 'W':{
					Dice[0]=Dice[2];
					Dice[2]=7-temp;
					break;
				}
				case 'R':{
					temp=Dice[1];
					Dice[1]=Dice[2];
					Dice[2]=7-temp;
					break;
				}
				case 'L':{
					temp=Dice[1];
					Dice[1]=7-Dice[2];
					Dice[2]=temp;
					break;
				}
				default: break;
			}

			sum+=Dice[0];
		}
		printf("%d\n", sum);
	}

}