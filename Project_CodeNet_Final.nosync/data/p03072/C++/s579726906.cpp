#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define H_MAX 50
#define W_MAX 50

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int H,W;

namespace patch {
  template < typename T > std::string to_string( const T& n )
  {
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
  }
}

int main() {
	int n;
	cin >> n;
	vector<int> vh;
	int h;

	rep(i,n) {
		cin >> h;
		vh.pb(h);
	}
	int count = 0;
	int tc;
	bool flag;
	rep(i,n) {
		if(i==0){
			count++;
			continue;
		}
		tc = 0;
		flag = true;
		while(tc < i){
			if(vh[tc] > vh[i]){
				flag = false;
				break;
			}
			tc++;
		}
		if(flag==false)
			continue;
		count++;
	}
	cout << count << endl;
  return 0;
}
 
