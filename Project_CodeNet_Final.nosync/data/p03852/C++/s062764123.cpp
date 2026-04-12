#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

char c;

int main(void){
    
    scanf("%c", &c);
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') printf("vowel\n");
    else printf("consonant\n");
    
    return 0;
}