	#include <bits/stdc++.h>
	using namespace std;
	int main(){
      int r,c,cnt=0;cin>>r>>c;
      for (int i=0;i<r;i++){
        string s;cin>>s;
        for (int j=0;j<c;j++){
          if (s[j]=='#') cnt++;
        }
      }
      if (cnt==r+c-1) cout << "Possible" << endl;
      else cout << "Impossible" << endl;
    }