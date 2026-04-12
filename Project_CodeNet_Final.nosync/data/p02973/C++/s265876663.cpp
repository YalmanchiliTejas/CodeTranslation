// agrawal117
//chahat agarwal
#include<bits/stdc++.h>  
#define mod 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long int ll;
ll dp[300000];
ll arr[300000];
ll n=10;
ll MinimumNumIncreasingSubsequences() 
{ 
	multiset<ll> last; 

	for (int i = 0; i < n; i++) { 

		multiset<ll>::iterator it = last.lower_bound(arr[i]); 

		if (it == last.begin()) 

			last.insert(arr[i]); 

		else { 
			it--; 

			last.erase(it); // erase the largest element smaller than arr[i] 
			last.insert(arr[i]); // and replace it with arr[i] 
		} 
	} 
	return last.size(); // our answer is the size of last 
} 
int main()
{
    cin>>n;
   
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        arr[i]=a;
    }
    cout<<MinimumNumIncreasingSubsequences(); 
}

