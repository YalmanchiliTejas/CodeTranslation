#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
#include<map>
#include<queue>
#include<functional>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define REV(v) reverse(v.begin(),v.end())

typedef long long ll;
typedef tuple<int,int,bool> Tb;


int atcoder(){
    //入力
    int n;
    cin >> n;
	    
    //処理
  if(n==3 || n==5 || n==7) cout << "YES" << ENT;
    else cout << "NO" << ENT;
    //出力
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
