#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    cin.tie(0);
	ios::sync_with_stdio(false);

    int a,b,ab,x,y,l,ans = 0;
    cin >> a >> b >> ab >> x >> y;

    if(a + b >= ab * 2){
        if(x > y){
            ans = ab * y * 2 + (x - y) * a;
        }
        else{
            ans = ab * x * 2 + (y - x) * b;
        }
    }
    else{
        ans = a * x + b * y;
    }

    int mx = max(x,y) * ab * 2;

    cout << min(mx,ans) << endl;

    return 0;
}