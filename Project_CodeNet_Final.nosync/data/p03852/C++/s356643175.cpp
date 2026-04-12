#include <bits/stdc++.h>
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
using namespace std;

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	string s;
	cin >> s;
	if(s[0]=='a'){
		cout << "vowel" << endl;
		return 0;
	}
	if(s[0]=='i'){
		cout << "vowel" << endl;
		return 0;
	}
	if(s[0]=='u'){
		cout << "vowel" << endl;
		return 0;
	}
	if(s[0]=='e'){
		cout << "vowel" << endl;
		return 0;
	}
	if(s[0]=='o'){
		cout << "vowel" << endl;
		return 0;
	}
	cout << "consonant" << endl;
return 0;
}