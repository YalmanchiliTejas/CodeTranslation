#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll answer = 0;
    if(c*2 >= a+b){
        cout << a*x + b*y << endl;
        return 0;
    }
    answer += min(x,y)*2*c;
    ll larger_price;
    ll amari = max(x,y) - min(x,y);
    if(x > y){
        larger_price = a;
    }
    else{
        larger_price = b;
    }
    if(larger_price <= 2*c){
        answer += amari*larger_price;
    }
    else{
        answer += amari*2*c;
    }
    cout << answer << endl;
    return 0;
}