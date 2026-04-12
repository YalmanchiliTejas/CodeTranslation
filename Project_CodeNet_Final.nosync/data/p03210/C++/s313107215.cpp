#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORRN(i,a,b) for (int i = (a); i >= (b); i--)
#define FORR(i,a,b) for (int i = (a); i > (b); i--)
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

    int n;
    cin >> n;

    if(n==5 || n==3 || n==7)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}