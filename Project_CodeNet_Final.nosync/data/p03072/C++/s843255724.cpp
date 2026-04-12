#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h> 
using namespace std;
	typedef long long int lli;
	const int MaxN=200005;
	#define fst first
	#define snd second
	#define mp make_pair
	lli mcd(lli a,lli b){	
		if(a==0)return b;
		return mcd(b%a,a);
	}		
	lli arr[MaxN];
int main(){
	lli N,K,i,j,res=0,maxi=0;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>arr[i];
	}
	for(i=0;i<N;i++){
		maxi=max(maxi,arr[i]);
		if(maxi==arr[i]){
			res+=1;
		}
	}	
	cout<<res;
	
}