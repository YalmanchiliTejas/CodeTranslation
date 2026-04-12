#include<bits/stdc++.h>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<cstdio>
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
# define ull unsigned long long int
# define ll long long int
# define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define vull vector<unsigned long long>
# define vll vector<long long>
# define vl vector<long>
# define vi vector<int>
# define vs vector<string>
# define vvi vector<vector<int>>
# define vii vector<pair<int,int>>
# define rep(i,a,b) for(int i=a;i<=b;i++)
# define pb push_back
# define pop pop_back
# define MOD 1e9+7
# define mp make_pair
# define F first
# define S second
# define all(v) v.begin(),v.end()
# define _ <<" "
//typedef _int128 Bigint;
using namespace std;
ull size[50];
double gcd(double a,double b)
{
    return a < 0.01 ? b : gcd(fmod(b,a),a);
}
ll max(ll a,ll b)
{
        return (a>b)?a:b;
}
ll max(ll a,ll b,ll c)
{
        return max(a,max(b,c));
}
ll min(ll a,ll b)
{
        return (a<b)?a:b;
}
ll min(ll a,ll b,ll c)
{
        return min(a,min(b,c));
}
void swap(ll *x,ll *y)
{
        ll temp;
        temp=*y;
        *y=*x;
        *x=temp;
}
ull patty(int level,ull x)
{
        if(x<=level)
        return 0;
        if(level==0)
        return 1;
        //if(x>size[level])
        //return pow(2,level+1);
        if(x<=size[level-1]+1)
        {
                return patty(level-1,x-1);
        }
        else if(x==size[level-1]+2)
        return pow(2,level)-1+1;
        else if(x>size[level-1]+2)
        return pow(2,level)-1+1+patty(level-1,x-2-size[level-1]);
}
int main()
{
//clock_t t=clock();
fastio;
/*int t;cin>>t;
while(t--)
{
        
}*/
int n;ull x;cin>>n>>x;size[0]=1;
for(int i=1;i<n;i++)
{
        size[i]=2*size[i-1]+3;
}
cout<<patty(n,x)<<endl;
//t=clock()-t;
//cout<<"Time is "<<(float)((float)t/CLOCKS_PER_SEC)<<endl;
return 0;
}