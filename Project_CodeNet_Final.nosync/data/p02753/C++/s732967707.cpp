#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <vector>	

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vl;

typedef pair<int,int> pi;
typedef pair<double,double> pd;

#define pb push_back
#define mp make_pair

#define endl "\n"
typedef long long ll;
typedef unsigned int uint;

inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}

int INF = 1e9+1;

int main(){
	fastio();
	string s;
	cin>>s;
	if (s[0] == 'A' && s[1] == 'B' || s[1] == 'A' && s[2] == 'B' || s[0] == 'B' && s[1] == 'A' || s[1] == 'B' && s[2] == 'A' )
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
