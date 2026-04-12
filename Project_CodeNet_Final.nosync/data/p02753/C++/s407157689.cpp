//21171_somesh || asomesh999

#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i=a;i<b;i++)
#define io ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
long int mod=1000000007;

int main()
{
	io
	#ifdef CODE
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	string s;
	cin >> s;
	set<char> st;
	fr(i,0, 3) {
		st.insert(s[i]);
	}
	if (st.size() == 2) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	#ifdef CODE
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}