#include <bits/stdc++.h>
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>0;--i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll gcd(ll a,ll b){while(a&&b)a>b?a%=b:b%=a;return a+b;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    char c;
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        cout<<"vowel"<<endl;
    else
        cout<<"consonant"<<endl;
    return 0;
}
