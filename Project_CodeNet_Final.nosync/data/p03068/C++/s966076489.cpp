#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    char p=s[k-1];
    REP(i,n){
        if(s[i]-p!=0) s[i]='*';
    }
    cout<<s<<endl;
}