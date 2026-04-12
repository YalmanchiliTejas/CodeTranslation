                         /*  (: ///////|||||| BEGINS |||||||\\\\ :) */
/* REMEMBER
Deletes all characters except first one     Deletes 4 characters from index number 1
    str.erase(1);                               str.erase(1,4);
Deletes character at position 4
 str.erase(str.begin() + 4);
bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}
maxn = max_element(mp.begin(), mp.end(), compare)->second;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}
priority_queue <int, vector<int>, greater<int>> gquiz; // to create min heap
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
const int inf=0x3f3f3f3f;
#define mod  1000000007
#define fo(i,n) for(int i=1;i<=n;i++)
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define three_max(n1,n2,n3) (n1 > n2)?(n1>n3?n1:n3):(n2>n3?n2:n3)
#define lb lower_bound
#define ub upper_bound
#define tr(it, a) for(auto it = a.begin();it!=a.end();it++)
#define gcd(a,b) __gcd(a,b)
#define pq priority_queue 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long isprime(long long n)
{
    for(long long i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n;
cin>>n;
if(n>=30)cout<<"Yes"<<endl;
else cout<<"No";

return 0;
}