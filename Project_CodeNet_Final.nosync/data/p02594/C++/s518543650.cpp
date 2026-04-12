//#include"bits/stdc++.h"
#include<algorithm>
#include<cassert>
#include<cmath>
#include<climits>
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define ll long long
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rep(i, j) FOR(i, 0, j, 1)
#define MP make_pair
#define PB push_back
#define endl "\n"
#define MOD 1000000007
#define DEB(x) cout<<"##"<<x<<"##"<<endl
const int INF=(int)2e9+9;
const int SIZE=(int)2e5+5;
//Brute force answers(BINARY SEARCH) symmetry
//Change perspective
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int x;
    cin>>x;
    if(x>=30){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
} 