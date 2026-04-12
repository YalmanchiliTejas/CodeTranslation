#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;

bool check(int a, string str)
{
	if(a%15 == 0)
		return str == "FizzBuzz";
	if(a%5 == 0)
		return str == "Buzz";
	if(a%3 == 0)
		return str == "Fizz";
	return a == atoi(str.c_str());
}

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m), n){
		set<int> player;
		rep(i, n)
			player.insert(i);
		
		set<int>::iterator itr = player.begin();
		rep(i, m){
			char str[1024];
			int len;
			do{
				fgets(str, 1024, stdin);
				len = strlen(str);
				if(str[len-1] == '\n'){
					str[len-1] = '\0';
					--len;
				}
			}while(len==0);
			
			if(player.size() > 1){
				if(check(i+1, str))
					++itr;
				else
					player.erase(itr++);
				if(itr == player.end())
					itr = player.begin();
			}
		}

		int roop = 0;
		for(itr=player.begin(); itr!=player.end(); ++itr, ++roop)
			printf("%d%c", *itr+1, roop+1==player.size() ? '\n' : ' ');
	}
	return 0;
}