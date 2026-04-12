#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long n,a,m,k,q,b,c=1;
float qq,ww,ff=2,qs;
string ss,s1,s2;
int main(){
    cin>>n;
    vector<int>v(n,0);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    for (int i=0; i<n; i++){
        a=max(a,v[i]*1ll);
        if (v[i]>=a){
            b++;
        }
    }
    cout<<b<<endl;
}
