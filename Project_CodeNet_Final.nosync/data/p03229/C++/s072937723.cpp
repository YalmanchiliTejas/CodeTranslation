/*
*******************
2018-10-28 Sun
*******************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
#define PI 3.14159265359
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
const int INF = 1<<29;
typedef unsigned long long ull;
typedef long long ll;
typedef long long int LL;

ll n;
ll A[100005];

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(NULL);
    cout.tie(NULL);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);	

    cin >> n;
    FOR(i,0,n)
        cin >> A[i];
    sort(A,A+n);

    vector<ll> b(n),c(n);
    int l=0,r=n-1;
    for(int i=1;i<n;i+=2)
        b[i]=A[l++],c[i]=A[r--];

    l=0,r=n-1;
    for(int i=2;i<n;i+=2)
        b[i]=A[r--],c[i]=A[l++];

    b[0]=A[r],c[0]=A[l];
    ll p=0,q=0;

    FOR(i,1,(int)b.size())
        p+=abs(b[i]-b[i-1]);
    FOR(i,1,(int)c.size())
        q+=abs(c[i]-c[i-1]);

    cout << max(p,q) << endl;

    return 0;
}
