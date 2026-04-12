#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <cmath>

#define FOR(i, f, n) for(int (i) = (f); (i) < (n); (i)++)
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (n); (i)--)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define step(i, f, n, a) for(int (i) = (f); (i) < (n); (i)+=a)
#define rstep(i, f, n, a) for(int (i) = (f); (i) >= (n); (i)-=a)
#define p(...) printf(__VA_ARGS__); cout << endl;
#define gets(x) x; cin >> x;
#define puts(x) x; cout << x << endl;
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](const a, const b){ return c ;}
#define key(t, x, compare) [](const t& a, const t& b){ return a x compare b x ;}

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll n;
string s, animals = "";

void animalAlignment(string start){
	animals = start;
	FOR(i, 1, n){ //2文字目から順に
		if (animals[i] == 'S'){
			if (s[i] == 'o'){
				animals += animals[i-1]; //等しい
			}else{
				animals += animals[i-1] == 'S'? 'W':'S'; //'x'の時
			}
		}else{ //Wの時
			if (s[i] == 'o'){
				animals += animals[i-1] == 'S'? 'W':'S'; //等しくない
			}else{
				animals += animals[i-1]; //'x'なら等しい
			}
		}
	}
	bool flag = false;
	if (animals[animals.size()-1] == animals[0]){
		animals.pop_back();
		flag = true;
	}

	if (flag){
		if (animals[0] == 'S'){
			if (s[0] == 'o'){
				if (animals[animals.size()-1] == animals[1]){
					puts(animals)
					exit(0);
				}
			}else{
				if (animals[animals.size()-1] != animals[1]){
					puts(animals)
					exit(0);
				}
			}
		}else{
			if (s[0] == 'o'){
				if (animals[animals.size()-1] != animals[1]){
					puts(animals)
					exit(0);
				}
			}else{
				if (animals[animals.size()-1] == animals[1]){
					puts(animals)
					exit(0);
				}
			}
		}
	}
}

int main(){
	gets(n) gets(s)
	animalAlignment("SS");
	animalAlignment("SW");
	animalAlignment("WS");
	animalAlignment("WW");
	puts(-1)

}
