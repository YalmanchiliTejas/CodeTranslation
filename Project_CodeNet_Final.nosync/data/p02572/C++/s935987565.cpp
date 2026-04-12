#include <bits/stdc++.h>
#define F first 
#define S second 
#define endl "\n"
#define Endl "\n"
#define emdl "\n"
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
bool sortBy(const pair<int,int> &a,const pair<int,int> &b){
	if(a.F==b.F)
		return a.S<b.S;
	return a.F>b.F;
}

// #define MAXN 1001
// int pf[MAXN]; 
// void sieve(){
// 	long long int i,j; 
//     pf[1] = 1; 
//     for (i=2; i<MAXN; i++) 
//     pf[i] = i;   
//     for (i=2; i*i<MAXN; i++){ 
//         if (pf[i] == i){
//             for (j=i*i; j<MAXN; j+=i) 
//                 if (pf[j]==j) 
//                     pf[j] = i; 
//         } 
//     } 
// }
// vector<int> factors(int x){ 
//     vector<int> ret; 
//     while (x != 1){ 
// 		int fact=pf[x];
//         ret.push_back(pf[x]); 
// 		while(fac!=1&&x%fact==0)
//         x/=fact; 
//     } 
//     return ret; 
// } 
// set<long long int>poww;
// void init(){
// 	long long int temp=1;
// 	for(int i=1;i<43;i++){
// 		poww.insert(temp);
// 		temp*=2;
// 	}
// }  
// long long int power(long long int a,int n){
//     if(n==1)
//     return a;
//     if(n%2){
//         return power()
//     }
// }

int main() {		
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int qwe=1;
	//cin>>qwe;
	//init();
	// sieve();
	while(qwe--){
       int n;
       cin>>n;
       long long int a[n],ans=0,fin=0;

       for(int i=0;i<n;i++){
           cin>>a[i];
           fin+=a[i];
       }
       for(int i=0;i<n;i++){
           ans+=(((fin-a[i])%1000000007)*(a[i]%1000000007));
           fin-=a[i];
           ans%=1000000007;
       }
        cout<<ans;


	}

	return 0;
}
