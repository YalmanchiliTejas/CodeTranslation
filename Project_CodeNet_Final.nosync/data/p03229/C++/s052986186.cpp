#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main(){
    int n;
    long long x[100000+5];
    cin >> n;
    for(int a = 0; a < n; a++) 
        cin >> x[a];
    sort(x, x+n);
    long long ans = 0;
    int a = 0; 
    int b = n-1;
    ans += x[b]-x[a];
    while(a < b){
        if(a+2 == b){
            ans += max(x[b]-x[a+1], x[b-1]-x[a]);
            break;
        }
        ans += x[b]-x[a+1]+x[b-1]-x[a];
        a++; b--;
    }
    cout << ans << endl;
    return 0;
}