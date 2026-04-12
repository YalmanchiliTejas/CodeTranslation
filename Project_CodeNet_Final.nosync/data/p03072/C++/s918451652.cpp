#include<bits/stdc++.h>
#include<cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const double PI=acos(-1.0);
const int INF=1e9;
const double EPS=1e-10;
const ll MOD=1e9+7;


int main(){
int n,h;
int cnt=0;
cin>>n;
vector<int> v(n);
REP(i,n){
cin>>v[i];
}
h=v[0];
REP(i,n){
if(v[i]>=h){
h=v[i];
cnt++;
}
}
cout<<cnt<<endl;
return 0;
}