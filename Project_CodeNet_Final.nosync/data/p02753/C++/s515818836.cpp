#include<bits/stdc++.h>
#define ll long long
#define sort(a) sort(a.begin(), a.end())
#define loop(n) for(ll i = 0; i<n; i++)
using namespace std;

int main(){
    int a = 0, b = 0;
    for(int i = 0; i<3; i++){
        char c;
        cin>>c;
        c=='A'?(a++):(b++);
    }
    if(a==0 || b==0) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}