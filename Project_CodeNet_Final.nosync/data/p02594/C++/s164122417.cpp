/*GRATITUDE*/
/*1916057*/
//Arise Awake and Stop Not Till the Goal is reached. 
//Break through all barriers..
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define endl            "\n"
#define PI                 acos(-1)
#define w(t)              int t; cin>>t; while(t--)
#define for_f(a,b,c)      for(int i=a;i<=b;i=i+c)
#define for_r(a,b,c)      for(int i=a;i>=b;i=i-c) 
#define trace1(x) cout << '>' << #x << ':' << (x) << "\n"
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
void ash_god()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

/*************************************************************************************************/
//Write your functions here..............................

/***************************************************************************************************/

void solve() {
/*Write your code here*/
 int x; cin>>x;
 if(x>=30) cout<<"Yes";
 else cout<<"No";
}
int32_t main()
{
ash_god();
bool tc=0;
if(tc)  {
    w(t) solve();
}
else solve();

return 0;
} 