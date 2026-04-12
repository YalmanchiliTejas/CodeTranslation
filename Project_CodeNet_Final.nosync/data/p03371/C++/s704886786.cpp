#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define vii vector<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;

string yn(bool x){
    return x ? "Yes" : "No";
}


int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    
    int res = a*x+b*y;
    
    for(int i= 0 ; i<=max(x,y)*2; i+= 2){
        int pA = x-i/2;
        int pB = y-i/2;
        if(pA<0) pA = 0;
        if(pB<0) pB = 0;
        
        int price = a*pA + b*pB + c*i;
        res = min(res,price);
    }
    
    cout << res << endl;
}





