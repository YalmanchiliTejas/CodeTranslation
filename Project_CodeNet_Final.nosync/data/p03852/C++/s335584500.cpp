#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){
    char c;
    cin >> c;
    if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') cout << "consonant" << endl;
    else cout << "vowel" <<endl;
    return 0;
}