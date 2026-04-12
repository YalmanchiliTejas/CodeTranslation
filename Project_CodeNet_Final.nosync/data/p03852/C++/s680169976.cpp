#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>



using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;


//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)



int main(void){

	char c; scanf("%c", &c);

	char vowel[5] = {'a', 'i', 'u', 'e', 'o'};

	bool ans = false;
	REP(i,5) if(vowel[i] == c) ans = true;

	if(ans == true) printf("vowel\n");
	else printf("consonant\n");


	return 0;

}
