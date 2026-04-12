//do not think about past and stay in this moment
//organize and work - Abhinav IIITA
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define int long long
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end() 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());




// -----------------------------------------------------------------------

int fre[26];
void solve(){
	char t;
	cin>>t;
	if(t=='a' || t=='e' || t=='i' || t=='o' || t=='u' ){
		cout<<"vowel";
	}else cout<<"consonant";
}


// -----------------------------------------------------------------------


int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 	
	int t=1;
//	cin>>t;
	while(t--)
	solve();
	return 0;
}
