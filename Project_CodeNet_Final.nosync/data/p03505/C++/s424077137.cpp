#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a,b,c,ans=0;
    cin>>a>>b>>c;
    if(b>=a){
        cout<<1<<endl;
        return 0;
    }
    if(c>=b){
        cout<<-1<<endl;
        return 0;
    }
    if((a-b)%(b-c)>0){
        ans++;
    }
    cout<<((a-b)/(b-c)+ans)*2+1<<endl;
}