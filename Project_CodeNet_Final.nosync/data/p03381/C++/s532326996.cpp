#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
//#define mp make_pair

int n, a[202020], b[202020];

int main(){

ios::sync_with_stdio(0);
cin.tie(0);

cin >> n;
rep(i, 1, n){
cin >> a[i];
b[i]=a[i];
}

sort(b+1, b+n+1);

rep(i, 1, n){

if(a[i]<=b[n/2])cout << b[(n)/2+1] << endl;
else cout << b[(n)/2] << endl;

}

}
