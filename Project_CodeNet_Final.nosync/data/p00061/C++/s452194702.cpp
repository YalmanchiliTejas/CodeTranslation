#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <list>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#define INF 10000000
#define I64 long long int
#define rep(i) for(I64 i=0;;++i)
#define rep2(i,n,m) for(I64 i=n;i<(m);++i)
using namespace std;

typedef vector<pair<int, int> > PV;

void swapPair(pair<int, int> &p1, pair<int, int> &p2){
	pair<int, int> temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

int main(){
	PV ranking;

	while(true){
		int num, score;
		scanf("%d,%d", &num, &score);
		if(!(num || score)) break;
		ranking.push_back( pair<int, int>(num, score) );
	}
	
	int n = ranking.size();
	for(int i=n;i>0;--i){
		for(int j=0;j<n-1;++j){
			if(ranking[j].second < ranking[j+1].second)
				swapPair(ranking[j], ranking[j+1]);
		}
	}
	
	
	PV res;
	int currentRank = 1;
	int bufScore = ranking[0].second;
	for(int i=0;i<n;++i){
		if(ranking[i].second < bufScore){
			currentRank++;
			bufScore = ranking[i].second;
		}
		
		res.push_back( pair<int, int>(ranking[i].first, currentRank) );
	}

	int input;
	while(cin >> input){
		for(int i=0;i<n;++i){
			if(res[i].first == input){
				cout << res[i].second << endl;
				break;
			}
		}
	}
}