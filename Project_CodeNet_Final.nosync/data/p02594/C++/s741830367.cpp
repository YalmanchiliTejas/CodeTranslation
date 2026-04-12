#include<bits/stdc++.h> 
#define AndIamIronMan ios::sync_with_stdio(false); cin.tie(0);cout.tie(0); 
#define M 1000000007 

#define int128 __int128
using namespace std; 
typedef  long long int lli; 

bool prime(lli );

int main(){
		
    AndIamIronMan;
	lli co=0,i,n,y,m,d,j,k,z,t,x=0,a,b,c;
//	cin>>t;
//	while(t--){
	cin>>n;
	if(n>=30)cout<<"Yes";
	else cout<<"No";
//	}
		
	return 0;
}

bool prime(lli n){
	bool x=true;
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			x=false;
		}	
	}
	return x;
}