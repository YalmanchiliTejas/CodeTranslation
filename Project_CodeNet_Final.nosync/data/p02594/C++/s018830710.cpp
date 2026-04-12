
#include <bits/stdc++.h> //全てのヘッダファイルをインクルード
 
//ループ
#define rep(i, n) for(int i = 0; i < (n); i++) //普通のループ
#define repr(i, n) for(int i = n; i >= 0; i--) //逆ループ
 
//型名省略
typedef long long ll;
//値
static const ll MX = 100005;
static const ll MX_ll = 1e18;
const double PI = acos(-1); //π
 
using namespace std;
 
//ソート
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
 
//#include "./lib/generic/search.h"

//文字列入力した小数値を小数点なくして返す
int changeDoubleToInt(string decimal){ 
    decimal.erase(1, 1); //小数点削除
    int n_decimal = atoi(decimal.c_str()); //c_strでchar*に変換後、atoiでintに変換
    return n_decimal;
}

//最大公約数
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

//素数判定(True/Falseを返却)
int IsPrime_tf(ll num){
    if (num < 2) return false; //0、1は素数でない
    else if (num == 2) return true; //2は素数
    else if (num%2==0) return false; // 偶数はあらかじめ除く
    for (ll i = 3; i*i <= num; i += 2){ //チェックは2～√nで十分
        if (num % i == 0) return false; //素数でない
    }
    return true; //素数である
}

//素数判定(割れる値を返却)
ll IsPrime_value(ll num){
    if (num < 2) return -1; //0、1は素数でない
    else if (num == 2) return 2; //2は素数
    for (ll i = 2; i*i <= num; i += 1){ //チェックは2～√nで十分
        if (num % i == 0) return i; //素数でない
    }
    return num; //素数である
}

int main(){
   int x;
   cin >> x;
   if(x>=30) cout << "Yes" << endl;
   else  cout << "No" << endl;
   return 0;
}