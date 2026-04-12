//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  i,j,k,l,x,y,z;
    string a,b;
    cin>>x>>y>>z;
    x-=z;
    cout<<max(0LL,x/(y+z))<<endl;
       return 0;
}



