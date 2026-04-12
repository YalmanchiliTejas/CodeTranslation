#include<bits/stdc++.h>
using namespace std;
#define int long long
#define tc int t; cin>>t; while(t--)
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007;
#define pb push_back
#define vi vector<int>
#define vc vector<char>
#define eb emplace_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define fo(i,x,n) for(int i=x;i<n;i++)
#define tz(x) __builtin_ctz(x)
#define csb(x) __builtin_popcount(x)
#define btoi(str,i) stoi(str,0,i)
#define ff first
#define ss second
const int inf=0x3f3f3f3f3f3f3f3f;


int32_t main(){
   
string s;cin>>s;
sort(all(s));
if(s[0]==s[2])cout<<"No";
else cout<<"Yes";

}