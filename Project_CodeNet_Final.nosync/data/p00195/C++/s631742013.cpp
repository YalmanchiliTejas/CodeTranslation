/*
 * src.cpp
 *
 *  Created on: 2016/07/27
 *      Author: joi
 */

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

typedef pair<int,char> P;

P p[5];

int main(){
	int a,b;
	do{
		cin>>a>>b;
		if (a || b){
			p[0]=P(a+b,'A');
			FOR(i,1,5){
				cin>>a>>b;
				p[i]=P(a+b,'A'+i);
			}
			sort(p,p+5);
			cout<<p[4].second<<" "<<p[4].first<<endl;
		}
	}while (a || b);
	return 0;
}