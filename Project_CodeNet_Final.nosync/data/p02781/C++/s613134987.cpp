#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {
	string N;
	ll K;
	cin >> N >> K;
	ll ans = 0;

	if(N.size()<K) {
		cout << 0 << endl;
		return 0;
	}

	// K = 1;
	if(K==1) {
		ans += N[0]-'0';
		ans += 9 * (N.size()-1);
	}
	
	if(K==2) {
		// **000...
		int headmax = (N[0]-'0')*10 + (N[1]-'0');
		for(int i=11; i<headmax+1; i++) {
			if(i%10 != 0) ans++;
		}

		// *0...*...
		if(N[1]!='0') {
			if(N.size()>2) {
				ans += (N[0]-'0') * (N.size()-2) * 9;
			} 
		} else {
			for(int i=10; i<headmax+1; i+=10) {
				if(N[0]-'0'!=i/10) {
					ans += (N.size()-2) * 9;
				} else {
					
					bool ok = false;
					for(int j=2; j<N.size(); j++) {
						if(!ok) {
							ans += N[j]-'0';
							if(N[j]!='0') ok = true;
						} else {
							ans += 9;
						}
					}

				}
			}
		}

		// 0....**
		if(N.size()>3) {
			ans += (N.size()-1) * (N.size()-2) / 2 * 9 * 9;
		}
	}

	if(K==3) {
		// ***000
		int headmax = (N[0]-'0')*100 + (N[1]-'0')*10 + (N[2]-'0');
		for(int i=111; i<headmax+1; i++) {
			if(i%10 != 0 && (i/10)%10 != 0) ans++;
		}
		//cout << "1: " << ans << endl;

		// **0...
		headmax = (N[0]-'0')*10 + (N[1]-'0');
		//cout << "head" << headmax << endl;
		for(int i=11; i<headmax+1; i++) {
			if(i%10 != 0) {

				if(N[2]=='0' && i==headmax ) {
					bool ok = false;
					for(int j=3; j<N.size(); j++) {
						if(!ok) {
							ans += N[j]-'0';
							if(N[j]!='0') ok = true;
						} else {
							ans += 9;
						}
					}
				} 
				else {
					ans += (N.size()-3) * 9;
				}
			}
		}
		//cout << "2: " << ans << endl;


		// *0*...
		if(N[1]!='0') {
			headmax = (N[0]-'0')*100 + (N[1]-'0')*10 + (N[2]-'0');
			for(int i=101; i<headmax+1; i++) {
				if((i/10)%10!=0) continue;
				if(i%10 != 0) ans += (N.size()-3) * 9;
			}

		} else { // head
			headmax = (N[0]-'0')*100 + (N[1]-'0')*10 + (N[2]-'0');
			//cout << "headmax " << headmax << endl;

			for(int i=101; i<headmax+1; i++) {
				if((i/10)%10!=0 || i%10==0) continue;

				if(headmax==i) {
					bool ok = false;
					for(int j=3; j<N.size(); j++) {
						if(!ok) {
							ans += N[j]-'0';
							if(N[j]!='0') ok = true;
						} else {
							ans += 9;
						}
					}
				} else {
					ans += (N.size()-3) * 9;
				}
			}

		} // *0*
		//cout << "3: " << ans << endl;


		// *00...
		if(N.size()>4) {
			if(N[1]!='0' || N[2]!='0') ans += (N[0]-'0') * (N.size()-3) * (N.size()-4) /2  * 9 * 9;
			else {
				headmax = (N[0]-'0');
				for(int i=1; i<headmax+1; i++) {
					if(i==headmax) {
						int cnt = 0;
						for(int j=3; j<N.size(); j++) {
							if(N[j]!='0' && cnt==0) {
								ans += (N[j]-'0'-1) * (N.size()-j-1) * 9;
								ans += 1 * (N.size()-j-1) * (N.size()-j-2) /2  * 9 * 9;
								cnt++;
							} else if(N[j]!='0' && cnt==1) {
								ans += (N[j]-'0');
								cnt++;
							}
						}
					} else {
						ans += (N.size()-3) * (N.size()-4) /2  * 9 * 9;
					}
				}
			}
		}
		//cout << "4: " << ans << endl;


		// 0...
		ans += (N.size()-1) * (N.size()-2) * (N.size()-3) / 6 * 9 * 9 * 9;
		//cout << "5: " << ans << endl;

	} // K = 3
	
	cout << ans << endl;
		
  return 0;
}