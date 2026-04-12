#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	string S;
	cin>>S;
	
	map<char,int> mp;
	for(int i=0;i<3;i++)mp[S[i]]++;
	
	if(mp['A']*mp['B']==0)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	
    return 0;
}

