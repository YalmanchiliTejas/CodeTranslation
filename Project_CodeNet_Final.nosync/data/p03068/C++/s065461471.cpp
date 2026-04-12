#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N;
	cin>>N;
	
	string s;
	cin>>s;
	
	int K;
	cin>>K;
	
	K--;
	
	for(int i=0;i<N;i++){
		if(s[K]!=s[i]){
			s[i] = '*';
		}
	}
	
	cout<<s<<endl;
	
	return 0;
}