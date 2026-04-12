/*
Author : Chandan Agrawal
College : Poornima College of Engg. jaipur, Raj
Mail : chandanagrawal23@gmail.com


" when you are not practicing someone else is ,
 and the day u meet them u will lose "

*/
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 200050

#define ll long long
#define ld long double
#define lli long long int

#define pb push_back
#define INF 1000000000000
#define mod 1000000007

// trignometric function always give value in Radians only
#define PI acos(-1) //3.1415926535897932384626433832795028
#define dsin(degree) sin(degree*(PI/180.0))
#define dcos(degree) cos(degree*(PI/180.0))
#define dtan(degree) tan(degree*(PI/180.0))

#define rsin(radian) sin(radian)
#define rcos(radian) cos(radian)
#define rtan(radian) tan(radian)

#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))

#define loop(i,n) for (lli i = 0; i < n; i++)
#define FOR(i,a,b) for (lli i = a; i < b; i+=1)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) int(x.size())
#define F first
#define S second

#define mii map<lli,lli>
#define mci map<char,lli>
#define vi vector<lli>
#define vbool vector<bool>
#define seti set<lli>
#define pii pair<lli,lli>
#define pcc pair<char,char>

#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (a/gcd(a,b))*b
#define abs(x) ((x < 0)?-(x):x)

#define endl '\n'

template <typename T>
void print(T x){cout<<x<<endl;}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<endl;}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<endl;}

#define scanarr(a,n) for(lli i=0;i<n;i++)    cin>>a[i];
#define scanvec(a,n) for(lli i=0;i<n;i++){ lli x ; cin>>x; a.pb(x);}

#define printarr(a,n) for(lli i=0;i<n;i++)   cout<<a[i]<<" "; cout<<endl;
#define printvec(vec) for(auto xt : vec) cout<<xt<<" ";    cout<<"\n";

#define FD(N) fixed<<setprecision(N)

#define deb(x) cout<<#x<<" "<<x<<endl;

// chandan1,2
void chandan1(){int y=1;return;}
void chandan2(){
        loop(i,10){
        lli x=1;
    }
    return(chandan1());
}


int main(){
fastio
lli t=1;
//cin>>t;
chandan2();
while(t--) {
    lli n;
    cin>>n;
    if(n>=30)
        print("Yes");
    else
        print("No");


  }
return 0;
}
