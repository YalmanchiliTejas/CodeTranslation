#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	
	string s; 
	cin >> s;
 
   for(int i=0;i<2;i++) {
    if (s[i] != s[i+1]) {
      cout << "Yes"<<endl;
      
      return (0);
    }
   }
 
  cout<< "No"<<endl;
	
	return 0;
}