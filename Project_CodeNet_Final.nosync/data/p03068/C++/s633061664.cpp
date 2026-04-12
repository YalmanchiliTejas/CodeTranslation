#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#include <cmath>
#include <stack>

#define Bigger(a,b) (a <= b)?b:a                   //大きい方を返す
#define Rep(i, n) for(int i = 0; i < n; i++)    //i=0 → i=nまでループ
#define Repr(i,n) for(int i = n; i <=0; i--)    //i=n → i=0までループ　
#define For(i, m, n) for(int i = m;i < n;i++)   //i=m → i=nまでループ
#define All(x) (x).begin(),().end()             //xの最初と最後のイテレータを返す 
#define Out(n) cout << n << endl


using namespace std;



int main(){
    int n,k;
    string s;

    cin >> n >> s >> k;

    string ans = s;

    char c = s[k - 1];
    Rep(i,n){
        if(s[i] != c){
            ans[i] = '*';
        }
    }

    Out(ans);





    return 0;
}