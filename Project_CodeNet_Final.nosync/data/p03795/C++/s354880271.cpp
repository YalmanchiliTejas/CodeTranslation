#include<bits/stdc++.h>
using namespace std;
#define ll long long
const unsigned int M = 1000000007;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(cin>>n){
        int s=n*800;
        if(n>=15)s-=(n/15)*200;
        cout<<s<<endl;
    }
}
