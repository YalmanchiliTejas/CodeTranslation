#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char x;
	cin >> x;
	if(x=='a'||x=='i'||x=='u'||x=='e'||x=='o'){
		cout << "vowel" << endl;
	}else{
		cout << "consonant" << endl;
	}
}