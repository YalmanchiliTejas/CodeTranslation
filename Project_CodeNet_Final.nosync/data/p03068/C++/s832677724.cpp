#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define REP(i,N) for(int i=0;i<N;i++)
int main(){
    int n,k;
    cin>>n;
    string s; cin>>s;
    cin>>k;
    char c=s[k-1];
    REP(i,n){
        s[i]=s[i]==c?c:'*';
    }
    cout<<s<<endl;
    return 0;
}