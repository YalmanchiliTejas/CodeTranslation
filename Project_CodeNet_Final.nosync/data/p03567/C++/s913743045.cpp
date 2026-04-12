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
//
//template <class T>
//T mmax(T a,T b){
//    if(a>=b){
//        return a;
//    }
//    return b;
//}
//template <class T>
//T mmin(T a,T b){
//    if(a<=b){
//        return a;
//    }
//    return b;
//}
//
//long long gcd(long long a, long long b){
//    if(a<b){
//        swap(a,b);
//    }
//    while(b){
//        long long r = a%b;
//        a=b;
//        b=r;
//    }
//    return a;
//}
//
//long long lcm(long long a, long long b){
//    return (a*b)/gcd(a,b);
//}
//
//long long isPrim(long long a){
//    if(a==1){
//        return a;
//    }
//    for(int i=2;i*i<=a;i++){
//        if(a%i==0){
//            return i;
//        }
//    }
//    return a;
//}
//
//long long mod_pow(long long x, long long n, long long mod){
//    //xのn乗を計算するのにn乗を2進表記にして計算
//    //x^22 = x^16 + x^4 + x^2
//    long long ret=1;
//    while(n>0){
//        if(n&1){
//            ret=(ret*x)%mod;//答えに付加
//        }
//        x=(x*x)%mod;//2乗
//        n >>=1;
//    }
//    return ret;
//}
//
//
struct XX{
    long long x;
    long long y;
    long long ix;
    long long iy;
};


class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.x) == (riRight.x)){
            return riLeft.y < riRight.y;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
                                        //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.x) > (riRight.x);
    }
};


////union-find
//int ppar[1000];
//int rrank[1000];
//
//void init(int n){
//    for(int i=0;i<n;i++){
//        ppar[i]=i;
//        rrank[i]=0;
//    }
//}
//
//int find(int x){
//    if(ppar[x]==x){
//        return x;
//    }else{
//        return ppar[x]=find(ppar[x]);
//    }
//}
//
//void unite(int x,int y){
//    x=find(x);
//    y=find(y);
//    if(x==y){
//        return;
//    }
//    if(rrank[x]<rrank[y]){
//        ppar[x]=y;
//    }else{
//        ppar[y]=x;
//        if(rrank[x]==rrank[y]){
//            rrank[x]++;
//        }
//    }
//}
//bool same(int x,int y){
//    return find(x)==find(y);
//}
//
////kruskal
//struct edge{
//    int u;
//    int v;
//    int cost;
//};
//
//bool comp(edge& e1,edge& e2){
//    return e1.cost < e2.cost;
//}
//
//edge es[1000];
//
//long long kruskal(int V,int E){//V:頂点数,E:辺数
//    sort(es,es+E,comp);
//    init(V);
//    long long res = 0;
//    for(int i=0;i<E;i++){
//        edge e = es[i];
//        if(!same(e.u,e.v)){
//            unite(e.u,e.v);
//            res+=e.cost;
//        }
//    }
//    return res;
//}

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

#define SEN 2000



int main(int argc, const char * argv[])
{
    //std::ios::sync_with_stdio(false);
    //scanf("%s",S);
    //scanf("%d",&N);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //cin >> x >> y;
    //テスト用
    //ifstream ifs( "1_06.txt" );
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S;
    cin >> S;
//    int A[100000];
//    for(int i=0;i<N;i++){
//        cin >> A[i];
//    }

    if(S.find("AC")!=string::npos){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    
    
    //ここまで
    //cout << "ans" << endl;改行含む
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    //printf("%f\n",pow(2,ans.size()));
    
    return 0;
}
