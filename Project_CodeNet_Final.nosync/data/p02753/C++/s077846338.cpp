#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,a[1000000],n,i,j,c,k,m,x,y;
    string s;
    cin>>s;
    n=s.length();
    c=0;
    for(i=0;s[i];i++){
        if(s[i]=='A')
        c++;
    }
    if(c==0 || c==n)
    cout<<"No";
    else
    cout<<"Yes";
    return 0;
}
