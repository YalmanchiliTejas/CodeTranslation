#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int num_AB=max(x,y)*2;
    int money=a*x+b*y;
    for(int i=0;i<=num_AB;i+=2){
        int num_A=max(0,x-i/2);
        int num_B=max(0,y-i/2);
        money=min(money,a*num_A+b*num_B+c*i);
    }
    cout << money << endl;
}