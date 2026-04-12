#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int No, score;
	vector<int> vc;
	map<int,int> f;
	map<int,int> rank;

	while( scanf("%d,%d", &No , &score ) , No|score ){
		if( !count(vc.begin(),vc.end(),score) ) vc.push_back( score );
		f[No] = score;
	}
	unique( vc.begin() , vc.end() );
	sort( vc.begin() , vc.end() );
	reverse( vc.begin() , vc. end() );
	for(int i=0 ; i<(int)vc.size() ; ++i )
		rank[ vc[i] ] = i+1;

	while( ~scanf("%d", &No ) ){
		printf("%d\n", rank[ f[No] ] );
	}
}