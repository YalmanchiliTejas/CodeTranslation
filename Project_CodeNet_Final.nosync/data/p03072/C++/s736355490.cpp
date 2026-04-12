#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int main(){
    int n,x,m,s=1;
    cin>>n>>m;
    --n;
    while(n--){
        cin>>x;
        if(x>=m) m=x, ++s;
    }
    cout<<s;
    return 0;
}
