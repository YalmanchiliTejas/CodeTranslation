#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <stdio.h>
#include <string.h>

using namespace std;

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define ll long long
#define ld long double 
#define str string
// freopen("firesafe.in", "r", stdin);
// freopen("firesafe.out", "w", stdout);

//map<ll,ll>mmap;
int main(){
   int a,b,c;
   cin>>a>>b>>c;
   int val=a*100+b*10+c;
   if(val%4==0){
    cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
   }
    
}