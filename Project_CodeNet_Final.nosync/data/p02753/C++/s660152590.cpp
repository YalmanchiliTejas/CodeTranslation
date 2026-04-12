#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    string S;cin>>S;
    sort(ALL(S));
    cout<<(S[0]!=S[2]?"Yes":"No")<<endl;
}
int main(){
    Main();
    return 0;
}