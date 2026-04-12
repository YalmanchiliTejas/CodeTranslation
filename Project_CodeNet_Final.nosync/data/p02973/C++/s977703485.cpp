#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i,n) for(ll i=0;i<n;i++)
#define fore(i,a,b) for(ll i=a;i<=b;i++)
#define ford(i,n) for(ll i=n-1;i>=0;i--)
#define fi first
#define se second
#define endl "\n"
#define all(a) a.begin(),a.end()
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.14159265

/*************************************************************************************/
void file(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}
/*************************************************************************************/

const ll maxn=2e5+1,mod=1e9+7;



int main(){

    sync
  //  file();
    
    int n;
    cin>>n;
    
    int ar[n];
    forn(i,n){
    	cin>>ar[i];
    }
    int ans = 0;
    multiset<int> ms;

    forn(i,n){
    	if(i==0) ms.insert(ar[i]);
    	else{
    		auto it = ms.lower_bound(ar[i]);
    		if(it==ms.begin()){
    			ms.insert(ar[i]);
    		}
    		else{
    			it--;
    			ms.erase(it);
    			ms.insert(ar[i]);
    		}
    	}
    }
    cout<<ms.size()<<endl;



  return 0;
}