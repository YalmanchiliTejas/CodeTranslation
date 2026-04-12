#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
using namespace std::chrono;
long long int p=1e9 +7;
int n;
ll seq[3000];
bool debugging=0;
bool outputcheck=0;
bool timecheck=0;
void init(){
    if(debugging){
        
    }
    else{
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>seq[i];
        }
        
    }
}
long long int modpower(ll b,ll po, ll mod=p){
    long long int ans=1;
    while(po){
        if(po&1){
            ans*=b;
            ans%=mod;
        }
        b*=b;
        b%=mod;
        po>>=1;
    }
    return ans;
}
ll solve(){
   ll value[n][n];
   for(int i=0;i<n;i++){
       value[i][i]=seq[i];
   }
   for(int range=1;range<n;range++){
       for(int i=0;i<n-range;i++){
            value[i][i+range]=max(seq[i]-value[i+1][i+range],seq[i+range]-value[i][i+range-1]);
       }
   }
   return value[0][n-1]; 
}
ll solvebad(){

}
int output(){
   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	//cin >>t;
	t=1;
    srand(time(0));
	while(t--){
	   init();
	   if(debugging){
	       if(outputcheck){
	          if(solve()!=solvebad()){//checking for random input
	             output();
	          }
	       }
	       if(timecheck){
	           auto start=high_resolution_clock::now();
	           solve();
	           auto stop=high_resolution_clock::now();
	           auto duration = duration_cast<microseconds>(stop - start);
	           cout<<duration.count()<<" Fast\n";
	           start=high_resolution_clock::now();
	           solvebad();
	           stop=high_resolution_clock::now();
	           duration = duration_cast<microseconds>(stop - start);
	           cout<<duration.count()<<" Slow\n";
	       }
	   }
	   else{
	       cout<<solve()<<"\n";//solving it correctly
	   }
	}
}