#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main(){
	int x,y;
	char ch;
	multimap<int,int> a;
	while(1){
		cin >> x >> ch >> y;
		if(x==0 && y==0) break;
		a.insert( make_pair(30-y,x) );
	}
		
	for(;;){
		int n;
		if(! (cin >> n) ) return 0;
		int rank=0;
		int score=-1;
		multimap<int,int>::iterator it;
		for(it=a.begin();it!=a.end();it++){
			 if(it->first != score){
                		score = it->first;
               			 ++ rank;
           		 }
           		 if(it->second == n){
             			   cout << rank << endl;
             			   break;
           		 }   
		}	
	}
}