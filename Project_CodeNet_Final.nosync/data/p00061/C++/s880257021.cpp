/*
	0061:Rank Checker
*/
#include	<cstdio>
#include	<iostream>
#include	<vector>
#include	<utility>
#include	<algorithm>

using namespace std;

typedef vector< pair<int, int> > VPII;

int main(void) {
	VPII numPointSet;		/*Storage of team-num and points*/
	VPII numRankSet;		/*Storage of team-num and rank*/
	
	/*Input data*/
	while(1) {
		int a, b;
		
		scanf("%d,%d", &a, &b);
		if(a == 0 && b == 0) { break; }
		
		numPointSet.push_back( pair<int, int>(b, a) );
	}
	
	/*Sort and make rank*/
	sort( numPointSet.begin(), numPointSet.end() );
	VPII::reverse_iterator it = numPointSet.rbegin();
	int pointST = it->first;
	int rank = 1;
	
	while(it != numPointSet.rend()) {
		if(pointST != it->first) {
			++rank;
			pointST = it->first;
		}
		numRankSet.push_back( pair<int, int>( it->second, rank ) );
		++it;
	}
	sort( numRankSet.begin(), numRankSet.end() );
	
	while(1) {
		int a;
		
		cin >> a;
		if( cin.eof() ) { break; }
		
		cout << numRankSet[a-1].second << endl;
	}
	
	return 0;
}