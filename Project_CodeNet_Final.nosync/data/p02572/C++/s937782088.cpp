/*--ILRS-- sr4saurabh  */
#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define pb push_back 
#define popb pop_back
#define mp make_pair
#define ve vector
#define vii vector < int >
#define vll vector < ll > 
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpl vector < pll >
#define fi first
#define sz size 
#define len length 
#define se second 
//const ll mod=998244353;
const ll mod = 1000000000+7;
const ll N=10000000+6;
#define M_PI           3.14159265358979323846
//--------------------------------------------



//--------------------------------------------





//============================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
       freopen ("INPUT.txt" , "r" , stdin);
       freopen ("OUTPUT.txt", "w" , stdout);
    #endif

	//THE WATER WAS DEEP, I DROWNED AND THEN CAME FLOATING UP,DEAD!!



       	int n;
       	cin>>n;
       	 ll arr[n];
       	 for(int i = 0 ; i < n ; i++)
       	 	cin>>arr[i];

       	 ll suff[n+1]; suff[n] = 0;
       	 for(int j = n-1; j >=0 ; j--)
       	 	suff[j] = (suff[j+1]  +  arr[j])%mod;

       	 ll ans =0;
       	 for(int i = 0; i < n-1 ; i++)
       	 	ans = (ans + (suff[i+1]*arr[i])%mod)%mod;

       	 cout<<ans;






return 0;
}