//Dragon_warrior7(IITK)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl cout << '\n'
#define sor(x) sort(x.begin(), x.end())
#define rev(v) reverse(v.begin(), v.end())
#define maxin(v) *max_element(v.begin(), v.end())
#define minin(v) *min_element(v.begin(), v.end())
#define sumall(vect) accumulate(vect.begin(), vect.end(), 0)
#define count(x, vect) count(vect.begin(), vect.end(), x)
#define lb(v, temp) lower_bound(v.begin(), v.end(), temp)
#define ub(v, temp) upper_bound(v.begin(), v.end(), temp)
#define fi first
#define se second
#define llmax 100000000000000000
#define deb(x) cout << #x << " " << x << "\n"
#define pll pair<ll, ll> 
#define vll vector<ll> 
#define rub cout << "------------------------------------\n"
//#define min(a, b, c) min(a, min(b, c))
//#define max(a, b, c) max(a, max(b, c))
void read(vector<ll> &v)
{
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
}

void print(vector<ll> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
ll n,m,a,b,temp;
string str;
//set<ll> s;
//vll v;
ll x;
ll t[51];
ll p[51];
ll recur(ll x,int level)
{
    if(level==0)
    {
        if(x<=0)
        return 0;
        else
        return 1;
    }
   if(x<=(t[level-1]+1))
   {
       return recur(x-1,level-1);
   }
   else
   {
       return p[level-1]+1+recur(x-2-t[level-1],level-1);
   }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cin>>x;
	t[0]=1;
	p[0]=1;
	for(int i=1;i<51;i++)
	{
	    t[i]=2*t[i-1]+3;
	    p[i]=2*p[i-1]+1;
	}
	cout<<recur(x,n);
}