#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++) //n回繰り返すときだけ使う普通はforで楽しないのがいいかな

using namespace std;
typedef long long int ll;
int main()
{        
    int a,b,c,x,y;
    int sum;
   
    cin >> a >> b >> c >> x >> y;
    int MIN =min(x,y);
    int ans =min(a+b,c*2)*MIN;
    x -=MIN;
    y -=MIN;
    ans +=min(a,c*2)*x +min(b,c*2)*y;
    cout << ans << endl;
    return 0;
    



}
