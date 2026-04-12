#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 100000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;
int N, K;
char str[10];
char aim;

signed main(void) {
cin >> N;
rep(i,N){
    cin >> str[i] ;
//    cout << str[i] << i ;
}
cin >> K;
aim = str[K-1];
//cout << aim <<endl;
rep(i,N){
    if(str[i]!=aim){
        str[i] = '*';
    }
}
rep(i,N){
    cout << str[i];
}


    return 0;
}
