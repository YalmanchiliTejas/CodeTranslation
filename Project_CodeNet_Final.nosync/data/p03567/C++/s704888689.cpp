#include <bits/stdc++.h>

using namespace std;

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef int64_t ll; typedef vector<int> VI; typedef pair<int,int> pii;
const ll mod = 1e9+7;

void dbg(){ cerr << "\n"; }  
template <typename T1,typename ...T2>
void dbg(const T1& p1, const T2&...pr){ cerr << p1 << ": "; dbg(pr...);}


int main(){
	string s;
	cin >> s;
	
	int z=s.find("AC");
	cout <<(z==-1? "No":"Yes") <<"\n";
	
	return 0;
}
