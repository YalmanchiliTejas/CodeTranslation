#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

int a,b,ab,x,y;

cin >> a >> b >> ab >> x >> y ;

int ans=0;
//まず、AかBのどちらかを満たすまで買う

ans=min(min(x,y)*(a+b),min(x,y)*2*ab);



//そこから、ABで買うかAorBで買うか決める
if(x>y)ans+=min((x-y)*a,(x-y)*2*ab);
else {ans+=min((y-x)*b,(y-x)*2*ab);}

cout <<ans <<endl;
return 0;

}
/*vector <int> a(3);
for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }*/