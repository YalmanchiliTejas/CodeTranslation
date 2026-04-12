#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb pushback
#define fr(i,n) for(int i=0;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)


int main() {
    string x;
	cin >> x;
    string ans;
    if(x=="a"||x=="i"||x=="u"||x=="e"||x=="o")ans="vowel";
    else ans = "consonant";
      cout << ans << endl;
}