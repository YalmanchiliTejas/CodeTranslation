#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define FIND(x, target) find(x.begin(),x.end(),target)
#define pb(x) push_back(x)
#define output(x) cout<<x<<endl
#define ERASE(x, n) erase(x.begin(), x.begin+n)
// #define int long long
#define P pair<int, int>
typedef long long ll;

const long long int MOD = 1e9+7;
const int INF = -1;

signed main(void) {
  	int N;
  	cin >> N;
  	vector<int> A;

  	// align in max -> min order
  	vector<int> Color;
  	rep(i, N) {
  		int tmp;
  		cin >> tmp;
  		A.pb(tmp);
  	}
  	
  	for(int i=0; i < N; i++) {
  		bool find = false;
  		int index = -1;
  		for (int j=Color.size(); j>0; j--) {
  			if (Color[j-1] < A[i]) {
  				if (j == Color.size()) {
  					find = true;
  					index = j-1;
  				} else if (j == 1) {
  					index = 0;
  				}
  				continue;
  			} else {
  				index = j;
  				break;
  			}
  		} 

  		if (find) {
  			Color[index] = A[i];
  		} else {
  			Color.pb(A[i]);
  		}

  		/*rep(j, Color.size()) {
  			cout << j << ": " << Color[j] << " ";
  		}
  		cout << endl;*/
  	}

  	cout << Color.size() << endl;
 	
	return 0;
}
