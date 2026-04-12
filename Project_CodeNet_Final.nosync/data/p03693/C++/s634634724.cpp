#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    // 引数の受け取り
    //
    cin >> a >> b >> c;

if((a*100+b*10+c)%4==0){
    cout << "YES"  << endl;
}else{
    cout << "NO"  << endl;
}
    // 出力
    return 0;
}

