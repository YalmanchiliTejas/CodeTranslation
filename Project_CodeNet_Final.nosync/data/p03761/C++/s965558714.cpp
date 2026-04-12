/*
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
typedef mp::cpp_int mint; //*/
#include <bits/stdc++.h>
#define  re(i,j,n) for(li i=(j);i<(n);i++)
#define  rep(i,n) re(i,0,(n))
#define  red(i,n) for(li i=n-1;i>=0;i--)
#define  all(a) begin(a),end(a)
#define  pb(a) push_back(a)
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
    int x[26][n];
    rep(i,26)rep(j,n)x[i][j]=0;
    string s;
    rep(i,n){
        cin>>s;
        for(char c:s) x[c-'a'][i]++;
    }
    rep(i,26) {
        int m=x[i][0];
        rep(j,n) m=min(m,x[i][j]);    
        rep(k,m) cout<<(char)(i+'a');
    }
    cout<<endl;
//    rep(i,26){rep(j,n)cout<<x[i][j]<<" "; cout<<endl;}
    return 0;
}