#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
#define inf 1000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n, x;

cin >> n;

if(n>=15){
    cout << n*800 - 200*(n/15) << endl;
}
else cout << n*800;


return 0;}
