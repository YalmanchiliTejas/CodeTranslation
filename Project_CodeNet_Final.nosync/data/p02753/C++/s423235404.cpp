#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void fileioe(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	freopen("error.txt","w",stderr);
}
#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define fioe() fileioe()
#else
#define fioe() 1
#endif

int main()
{
	GO
	//fioe();
	string s;
	cin>>s;
	bool A=0,B=0;
	for(ll i=0;i<3;i++){
		if(s[i]=='A')A=true;
		else B=true;
	}
	if(A&&B){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}