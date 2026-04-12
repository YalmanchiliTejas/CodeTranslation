#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using pii=pair<int,int>;
using vi=vector<int>;
using vis=vector<string>;
using vvi=vector<vi>;
//pとqの最大公約数
int gcd(int p,int q){
    if(p%q==0)
    return q;
    return gcd(q,p%q);
}
int main(void){
    string s;
    cin>>s;
    if(s=="AAA"||s=="BBB")
    cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
    }
    
}