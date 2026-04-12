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
    int a,b;
    cin>>a>>a>>b;
    cout<<(((a*10+b)%4)?"NO":"YES")<<endl;
    
    return 0;
}
