#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    char c;
    cin >> c;
    if(c == 'a'||c=='i'||c=='u'||c=='e'||c=='o'){
        puts("vowel");
    }else{
        puts("consonant");
    }
    return 0;
}