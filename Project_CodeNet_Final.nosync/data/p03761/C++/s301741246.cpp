#include <bits/stdc++.h>
#define  ren(i,j,n) for(li i=(j);i<(n);i++)
#define  rep(i,n) ren(i,0,(n))
#define  all(a) begin(a),end(a)
using namespace std;
typedef long int li;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<li> vli;
typedef vector<string> vs;
 
int main()
{
    int n;
    cin>>n;
    int a[26][n];
    rep(i,26)rep(j,n)a[i][j]=0;
    rep(i,n){
        string s;
        cin>>s;
        for(char c:s) a[c-'a'][i]++;
    }
//    rep(i,26){rep(j,n) cout<<a[i][j]<<" "; cout<<endl;}
    rep(i,26){
        int m=50;
        rep(j,n) m=min(a[i][j],m);
        rep(q,m) cout<<char('a'+i);
    }
    cout<<endl;
    return 0;
}