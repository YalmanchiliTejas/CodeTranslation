#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++) 
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
	int N;
  cin >> N;
  vector<int> H(N);
  int mx = 0;
  int count = 0;
  rep(i,N) {
    int tmp;
    cin >> tmp;
    if(tmp >= mx) count++;
    mx = max(mx,tmp);
  }
  cout << count << endl;

}