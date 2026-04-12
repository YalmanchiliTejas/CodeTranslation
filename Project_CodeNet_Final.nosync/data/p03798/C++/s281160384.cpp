#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define vecp(p) int aa;cin>>aa;(p).push_back(aa);
#define vecpl(p) long long aa;cin>>aa;(p).push_back(aa);
#define vecps(p) string aa;cin>>aa;(p).push_back(aa);
#define vecp2(p) cin>>aa;(p).push_back(aa);
#define vecpl2(p) long long a	b;cin>>ab;(p).push_back(ab);
#define vecps2(p) string ab;cin>>ab;(p).push_back(ab);
#define set0(k,n) for(int nn=0;nn<(n);nn++){ (k).push_back(0); }
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define vecsize(b,size) vector<int> (b)((size));
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsl(s) vector<pair<ll,ll>> (s);
#define pairss(s) vector<pair<string,string>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairspl(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairsps(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairsREV(s) (s).push_back(make_pair(bb,aa));
#define pairslREV(s) (s).push_back(make_pair(bb,aa));
#define pairssREV(s) (s).push_back(make_pair(bb,aa));
#define MOD 1000000007

int N;
string S;

string check(string s1) {

	for (int x = 1; x < N - 1; x++) {
		if (S[x] == 'o') {
			if (s1[x] == 'W') {
				if (s1[x - 1] == 'W') {
					s1 += "S";
				}
				else {
					s1 += "W";
				}
			}
			else {
				s1 += s1[x - 1];
			}
		}
		else {
			if (s1[x] == 'W') {
				s1 += s1[x - 1];
			}
			else {
				if (s1[x - 1] == 'W') {
					s1 += "S";
				}
				else {
					s1 += "W";
				}
			}
		}
	}

	if (S[0] == 'o') {
		if (s1[0]=='W') {
			if (s1[1]==s1[N-1]) {
				return "";
			}
		}
		else {
			if (s1[1] != s1[N - 1]) {
				return "";
			}
		}
	}
	else {
		if (s1[0] == 'S') {
			if (s1[1] == s1[N - 1]) {
				return "";
			}
		}
		else {
			if (s1[1] != s1[N - 1]) {
				return "";
			}
		}
	}

	if (S[N-1] == 'o') {
		if (s1[N-1] == 'W') {
			if (s1[0] == s1[N - 2]) {
				return "";
			}
		}
		else {
			if (s1[0] != s1[N - 2]) {
				return "";
			}
		}
	}
	else {
		if (s1[N-1] == 'S') {
			if (s1[0] == s1[N - 2]) {
				return "";
			}
		}
		else {
			if (s1[0] != s1[N - 2]) {
				return "";
			}
		}
	}
	return s1;
}

int main()
{

	cin >> N >> S;
	string s1="WW", s2="SW",s3="SS",s4="WS";
	string T[4] = { "WW",  "SW", "SS", "WS" };
	bool flag = true;
	fx(4) {
		string t = check(T[x]);
		if (t!="") {
			ce(t)
				flag = false;
			break;
		}
	}

	if (flag) {
		ce(-1)
	}

    return 0;
}

