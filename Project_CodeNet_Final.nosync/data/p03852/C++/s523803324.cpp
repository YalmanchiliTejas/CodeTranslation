#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	char buf[2];

	scanf("%s",buf);

	if(buf[0] == 'a' || buf[0] == 'i' || buf[0] == 'u' || buf[0] == 'e' || buf[0] == 'o'){

		printf("vowel\n");

	}else{

		printf("consonant\n");
	}

	return 0;
}
