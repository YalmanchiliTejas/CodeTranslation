#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <climits>
#include <sstream>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

string FB(int n){
	if(n%3==0 && n%5==0)return "FizzBuzz";
	if(n%3==0)return "Fizz";
	if(n%5==0)return "Buzz";
	stringstream ss;
	ss<<n;
	return ss.str();
}

main(){
	int m,n;
	while(scanf(" %d%d ",&m,&n),m){
		set<int> play;
		for(int i=0;i<m;i++)play.insert(i);
		
		int cur=0;
		for(int i=0;i<n;i++){
			string word;
			cin>>word;
			if(play.size()==1)continue;
			while(play.count(cur)==0 && !play.empty())cur=(cur+1)%m;
			if(word==FB(i+1))cur=(cur+1)%m;
			else play.erase(cur),cur=(cur+1)%m;
		}
		if(!play.empty())cout<<*play.begin()+1;
		set<int>::iterator p=play.begin();
		for(++p;p!=play.end();++p)cout<<" "<<*p+1;
		cout<<endl;
	}
}