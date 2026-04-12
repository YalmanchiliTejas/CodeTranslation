#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define INF INT_MAX/3
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int,int>
#define PCC pair<char,char>
#define PCI pair<char,int>
#define PIC pair<int,char>
#define MP make_pair
#define DEBUG(x) cout<<#x<<": "<<x<<endl;

int main()
{
	int n;
	for (; cin >> n, n != 0;)
	{
		int Min = INF;
		int Max = -1;
		int sum = 0;
		REP(i, n)
		{
			int temp;
			cin >> temp;
			Min = min(Min, temp);
			Max = max(Max, temp);
			sum += temp;
		}
		sum =sum - Min - Max;
		int ans = sum / (n-2);
		cout <<ans<< endl;
	}
	return 0;
}