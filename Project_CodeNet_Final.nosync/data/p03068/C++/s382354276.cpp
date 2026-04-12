#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define bug cout<<"AIkahne aise"<<endl
ll A[5000001];
vector<ll>v;
vector<pair<ll,ll> >v2;
/*void sieve()
{
    for(ll i=3; i<=2000; i+=2)
    {
        for(ll j=i*i; j<=4000000; j+=i)
            A[j]=1;
    }
    v.push_back(2);
    for(ll i=3; i<=4000000; i+=2)
        if(A[i]==0)
            v.push_back(i);
}*/
int main()
{
    ll n,k;
 string s;
 cin>>n;
 cin>>s;
 cin>>k;
 char h=s[k-1];
 for(int i=0;i<s.size();i++)
 {
     if(s[i]!=h)
        s[i]='*';
 }
 cout<<s<<endl;
return 0;
}
