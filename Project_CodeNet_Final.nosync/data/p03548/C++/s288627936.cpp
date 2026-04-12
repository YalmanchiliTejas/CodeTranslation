#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000


int main(){

	int X,Y,Z;
	cin>>X>>Y>>Z;
	X-=Z;
	
	cout<<X / (Y+Z)<<endl;
	
    return 0;
}

