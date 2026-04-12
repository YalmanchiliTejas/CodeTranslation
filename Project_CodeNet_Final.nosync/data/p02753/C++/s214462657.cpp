#include<bits/stdc++.h>
using namespace std;
#include<string>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define intarr(arr, n)  ll arr[n];  for (ll i = 0; i < n; i++)  cin >> arr[i]
#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
const ll mod=1e9+7;

bool subsequence_checker(string str1, string str2, ll m, ll n) 
{ 
    if (m == 0) return true; 
    if (n == 0) return false; 
    if (str1[m-1] == str2[n-1]) 
        return subsequence_checker(str1, str2, m-1, n-1); 
    return subsequence_checker(str1, str2, m, n-1); 
}


void solve(){

    string s;
    cin>>s;

    if(s[0]!=s[1]  || s[1]!=s[2])
        cout<<"Yes";
    else
        cout<<"No";

    return;
}

int main()
{
    IOS;
    ll t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
 
    return 0;
}       