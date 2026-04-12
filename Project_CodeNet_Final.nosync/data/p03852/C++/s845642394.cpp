#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair

bool isvowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main()
{
    char c;cin>>c;
    if(isvowel(c)) cout<<"vowel";
    else cout<<"consonant";
}
