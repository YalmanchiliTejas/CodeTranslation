/*
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
typedef mp::cpp_int mint; //*/
#include <bits/stdc++.h>
#define  re(i,j,n) for(li i=(j);i<(n);i++)
#define  rep(i,n) re(i,0,(n))
#define  red(i,n) for(li i=n;i>0;i--)
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
    char c;
    cin>>c;
    cout<<((c=='a'||c=='i'||c=='u'||c=='e'||c=='o')?"vowel":"consonant")<<endl;

    return 0;
}
