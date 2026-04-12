#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
using vi=vector<int>;  using vs=vector<string>; using gi=greater<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define soao(c) sort((c).begin(),(c).end()) //昇順
#define sodo(c) sort((c).begin(),(c).end(),gi()) //降順
#define rev(c) reverse((c).begin(), (c).end())



int main(){
    int r,g,b; cin>>r>>g>>b;
    if((g*10+b)%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
