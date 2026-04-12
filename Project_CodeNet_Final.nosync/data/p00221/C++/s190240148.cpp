#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cctype>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<30;

bool fizzBuzzCheck(int n,string s){
	if(n%15==0)return (s == "FizzBuzz");
	if(n%3==0)return  (s == "Fizz");
	if(n%5==0)return  (s == "Buzz");

  REP(i,s.size()) if (!isdigit(s[i])) return false;

	return (atoi(s.c_str()) == n);
}

int main(){
	int n,m;
	string s;
	
	while(scanf("%d %d\n",&m,&n), m||n){
	
		vector<int> rem(m);
		for(int i=0;i<m;i++){
			rem[i] = i+1;
		}
		int c = 0;
		for(int i=1;i<=n;i++){
			getline(cin,s);
			if(rem.size() == 1)continue;
			if( !fizzBuzzCheck(i,s) ){
        rem.erase(rem.begin()+c);
			}else{
				c++;
			}
			c %= rem.size();
		}
    REP(i,rem.size())
			cout << (i?" ":"") << rem[i];
		cout << endl;
	}
}