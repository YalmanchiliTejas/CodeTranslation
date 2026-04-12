#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>

const int MOD=1000000007; //10^9+7
const double PI=3.1415926535;

int main(){
    string S;
    cin>>S;
    if(S=="AAA" || S=="BBB"){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}