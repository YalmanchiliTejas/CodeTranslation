#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    ll a=0,b=0,c=0;
    a=A*X+B*Y;
    b=C*max(X,Y)*2;
    if(X>Y) {
        c+=Y*2*C;
        c+=(X-Y)*A;
    }
    else if(X<Y) {
        c+=2*X*C;
        c+=(Y-X)*B;
    }
    else if(X==Y) {
        c+=X*2*C;
    }
    cout<<min(a,min(b,c))<<endl;
}