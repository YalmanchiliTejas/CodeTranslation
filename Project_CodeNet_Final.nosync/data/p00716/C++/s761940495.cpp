
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1135&lang=jp

#include <algorithm>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//テ」ツδ榲」ツつッテ」ツδュテ・ツョツ堙ァツセツゥ
#define ALL(v) (v).begin(),(v).end()
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define SORT(x) sort(begin(x),end(x))
#define SELECT_SORT(x, n) sort(begin(x),begin(x)+n)
#define SWAP(type, a, b) do {type tmp = a; a = b; b = tmp;} while (0)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))

//テ・ツョツ堙ヲツ閉ー
#define INF 2000000000000
#define MAX 10

//DEBUGテァツ板ィ
#define BAR() cout << "----------------------------" << endl;
#define DUMP(v) (cerr << #v << ": " << v << endl)
#define PRINT(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;


int main()
{
	int m,money,y,n;
	int a,c;
	long double risi;
	cin >> m;
	while(m)
	{
		cin >> money;
		cin >> y;
		cin >> n;

		int ans=0;

		int moneytmp = money;
		rep(i,n){
			cin >> a >> risi >> c;
			int tmpRisi=0;
			int anstmp=0;
			
			moneytmp = money;	
			if(!a){
				//テ・ツ債佚・ツ按ゥ
				rep(i,y)
				{
					tmpRisi += moneytmp*risi;
					moneytmp -= c;	
				}
				anstmp = moneytmp + tmpRisi;
			}else{
				//テァツヲツ湘・ツ按ゥ
				rep(i,y)
				{
					moneytmp +=moneytmp*risi-c;
				}
				anstmp=moneytmp;
			}
			ans = max(ans, anstmp);
		}
		cout << ans << endl;
		m--;
	}
	return 0;
}