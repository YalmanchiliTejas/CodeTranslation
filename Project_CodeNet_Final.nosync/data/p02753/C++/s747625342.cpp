#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	char tmp = s[0];
	int Count = 1;
	for(int i=1; i <=2; i++){
        if( s[i] == tmp ) ++Count;;
	}
	if(Count==3) cout << "No";
	else{
        cout << "Yes";
	}
 }
