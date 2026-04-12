#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>

using namespace std;

#define INT_MAX_VALUE 2147483647
#define LONG_LONG_MAX_VALUE 9223372036854775807
#define ll long long

struct XX{
    ll la;
    ll lb;
    ll ra;
    ll rb;
    ll q;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.q) == (riRight.q)){
            return riLeft.q < riRight.q;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.q) < (riRight.q);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}

int asum(string P){
    int sum=0;
    int strength=1;
    for(int i=0;i<P.size();i++){
        if(P.substr(i,1)=="S"){
            sum+=strength;
        }else{
            strength*=2;
        }
    }
    return sum;
}

int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs( "1_06.txt" );//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    int x[200000];
    int xx[200000];
    for(int i=0;i<N;i++){
        cin >> x[i];
        xx[i]=x[i];
    }
    sort(x,x+N);
    int m1=x[N/2-1];
    int m2=x[N/2];
    
    for(int i=0;i<N;i++){
        if(xx[i]<m1){
            cout << m2 << endl;
        }else if(xx[i]==m1){
            cout << m2 << endl;
        }else if(xx[i]==m2){
            cout << m1 << endl;
        }else{
            cout << m1 << endl;
        }
    }
    
    
    
    //ここまで
    //cout << "ans" << endl;改行含む
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}

