#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
//#define int long long  
int main(){
	string S;
	cin >> S;
	REP(i,S.size()-1){
	    if(S[i]=='A'&&S[i+1]=='C'){
	        cout << "Yes" << endl;
	        return 0;
	    }
	}
	cout << "No" << endl;
	return 0;
}