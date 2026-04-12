#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll k,a,b;
    cin>>k>>a>>b;
    if(k>a&&a<=b)cout<<-1<<endl;
    else if(k<=a)cout<<1<<endl;
    else {
       if((k-a)%(b-a)==0) cout<<(k-a)/(a-b)*2+1<<endl;
       else cout<<(k-a)/(a-b)*2+3<<endl;
    }
}