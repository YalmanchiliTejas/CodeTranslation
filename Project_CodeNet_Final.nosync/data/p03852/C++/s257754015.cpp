#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

#define F           first
#define S           second
#define pb          push_back
#define P           push


int main() {
    #ifdef LU_Serious
        freopen("in.txt", "r", stdin);
    #endif /// LU_Serious
    
    char ch;
    
    while(cin >> ch) {
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') printf("vowel\n");
        else printf("consonant\n");
    }
    
    return 0;
}
