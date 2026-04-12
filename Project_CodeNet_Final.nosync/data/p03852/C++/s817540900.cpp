#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	char a;
    scanf("%c",&a);
    if(a =='a' || a =='e' || a =='i' || a =='o' || a =='u' ){
        printf("vowel\n");
    }
    else{
        printf("consonant\n");
    }
	return 0;
}