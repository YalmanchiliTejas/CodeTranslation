#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

string gcs(string x, string y){
	vi a(26,0), b(26,0);
  	rep(s,x.size()) {
   		rep(i,26) {
          	if(x[s] == 'a'+i) a[i]++;
        }
    }
  	rep(s,y.size()) {
    	rep(i,26) {
          	if(y[s] == 'a'+i) b[i]++;
        }
    }
    string ans = "";
    rep(i,26) {
      	rep(j,min(a[i],b[i])) {
        	ans += 'a'+i;
      	}
    }
    return ans;
}

void Main()
{
	int n;
  	cin >> n;
  	vector<string> s(n);
	string stemp;
  	//cout << gcs("ab", "aa");

  	rep(i,n) {
      cin >> s[i];
      if(i == 0) stemp = gcs(s[0],s[0]);
      else stemp = gcs(stemp, s[i]);
    }
  	cout << stemp << endl;

	return;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}
