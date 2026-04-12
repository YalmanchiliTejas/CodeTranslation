#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string st;
	cin>>st;
	for(int i=0; i<st.length()-1; i++){
		if(st[i]=='A' && st[i+1]=='C'){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	
	return 0;
}
