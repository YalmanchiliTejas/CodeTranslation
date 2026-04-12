#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 5000001
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
const ll INF = 10010010010001;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if((a+b) > c*2){
        int t1 = 0,t2 = 0;
        t1 += min(x,y)*(c*2);
        if(x > y){
            t1 += (x-y)*a;
        }
        else{
            t1 += (y-x)*b;
        }
        t2 += max(x,y)*(c*2);
        ans = min(t1,t2);
    }
    else{
        ans += x*a;
        ans += y*b;
    }
    cout << ans << endl;
}
