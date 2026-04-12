#include <bits/stdc++.h>
#define e erase
#define PB push_back
#define elif else if
#define forn(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
using namespace std;
	
typedef long long int lli;
typedef long int li;
typedef vector <int> vi;
typedef vector <long long int> vii;
	
	
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	string inp;
	char simp;

	cin>>a>>inp>>b;

	simp = inp[b-1];

	forn(i, inp.length()){
		if(inp[i] != simp){
			inp[i] = '*';
		}
	}

	cout<<inp<<endl;
	
	return 0;
}
