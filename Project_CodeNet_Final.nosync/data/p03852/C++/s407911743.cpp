#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;

int main(){
	char c;
	scanf("%c",&c);

	if (c =='a'|| c =='e'|| c =='i'|| c =='o'|| c =='u'){
		printf("vowel\n");
	}else{
		printf("consonant\n");
	}

		return 0;
}
