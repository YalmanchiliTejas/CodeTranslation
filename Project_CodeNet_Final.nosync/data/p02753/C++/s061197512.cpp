
// Problem : A - Station and Bus
// Contest : AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include<bits/stdc++.h>
using namespace std;
#define ff first
#define fs second
#define int long long
#define vi vector<int>
#define vvi vector< vector <int> >
#define vpii vector< pair<int, int> >
#define vb vector<bool>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define md 1000000007
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define r(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define qw1(x) cerr<<#x<<": "<<x<<" "<<endl
#define qw2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define qw3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define qw4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

void sieve(int n, vb &prime)
{
    prime[0]=false;     prime[1]=false;
    for(int i=2;i*i<=n;i++){
         if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i)    prime[j]=false;
             }
    }
}
int32_t main ()
{
  //ios_base::sync_with_stdio (false); cin.tie (NULL);  cout.tie (NULL);
   string s;	cin>>s;
   if(s[0]==s[1] && s[1]==s[2]) cout<<"No";
   else cout<<"Yes";
 
}






