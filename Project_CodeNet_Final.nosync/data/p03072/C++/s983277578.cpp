#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define sz size
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORRN(i,a,b) for (int i=(a);i>=(b);i--)
#define FORR(i,a,b) for (int i=(a);i>(b);i--)
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); //Fast I/O
    cin.tie(0);
    cout.tie(0);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

    int n;
    cin >> n;
    vector<int> A(n);

    for(auto &i: A)
        cin >> i;

    int cc=0;
    
    FOR(i,0,n){
        bool flag=true;
        FOR(j,0,i){
            if(A[j]>A[i]){
                flag=false;
                break;
            }
        }
        if(flag)
            cc++;
    }

    cout << cc << endl;

    return 0;
}
