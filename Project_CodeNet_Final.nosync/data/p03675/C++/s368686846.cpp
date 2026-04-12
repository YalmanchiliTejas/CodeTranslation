/*
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::cpp_int mint; //*/
#include <bits/stdc++.h>
#define  re(i,j,n) for(li i=(j);i<(n);i++)
#define  rep(i,n) re(i,0,n)
#define  red(i,n) for(li i=(n)-1;i>=0;i--)
#define  all(a) begin(a),end(a)
#define  pb(a) push_back(a)
using namespace std;
using li = long int;
using ull= unsigned long long;
using vi = vector<li>;
using vs = vector<string>;


int main()
{
    li n;
    cin>>n;
    li a[n];
    rep(i,n)cin>>a[i];
    for(int i=n-1;i>=0;i-=2) cout<<a[i]<<" ";
    for(int i=n%2;i<n;i+=2) cout<<a[i]<<" ";
    cout<<endl; 
    
    return 0;
}

