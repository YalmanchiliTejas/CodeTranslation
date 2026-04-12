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
    int a,b,ab,x,y;
    cin >> a >> b >> ab >> x >> y;
    int answer = INT32_MAX;
    int tmp = 0;
    for(int i=0;i < 200001;i+=2){
        tmp = 0;
        tmp += i*ab;
        tmp += max(0,x-i/2)*a;
        tmp += max(0,y-i/2)*b;
        answer = min(answer,tmp);
    }
    
    cout << answer << endl;
    return 0;
}