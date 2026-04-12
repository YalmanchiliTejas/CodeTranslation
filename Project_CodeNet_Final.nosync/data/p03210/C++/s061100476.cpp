#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin >> x;
  	bool ans = false;
  	if(x==5 || x==3 || x==7){
    	ans = true;
    }
  	if(ans) cout << "YES";
  	else cout << "NO";
  	return 0;
}