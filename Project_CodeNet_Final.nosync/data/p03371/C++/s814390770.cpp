#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;


int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int one = a*x + b*y;
    int two = 2*c*max(x,y);
    int three=INF,four=INF;
    if(y>x) three = 2*c*x + b*(y-x);
    else if(x>y) four = 2*c*y + a*(x-y);
    cout << min({one,two,three,four}) << endl;
}