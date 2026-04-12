/*BINH :))*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long llu;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f  first
#define s  second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)
#define EL cout<<endl
#define max 1005
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
void init(){
}
int main(){
    IO
    init();
    string s;
    cin>>s;
    int a=0,b=0;
    FOR(i,0,2)if(s[i]=='A')a++;else b++;
    if(a!=0&&b!=0)cout<<"Yes";else cout<<"No";
}

