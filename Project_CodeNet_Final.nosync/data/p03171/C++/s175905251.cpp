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
#define ld long double

struct XX{
    ll x;
    ll a;
    ll b;
    int i;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.x) == (riRight.x)){
            return riLeft.i > riRight.i;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.x) > (riRight.x);
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

//int n;
////int dat[2*10000000];
////int dat2[2*10000000];
//int dat[10];
//int dat2[10];
//
//void init(int n_){
//    n=1;
//    while(n<n_)n*=2;
//    for(int i=0;i<2*n-1;i++){
//        dat[i]=0;
//        dat2[i]=0;
//    }
//}
//
//void initset(int k,int a){
//    k+=n-1;
//    dat[k]=a;
//    while(k>0){
//        k=(k-1)/2;
//        dat[k]=dat[k*2+1]+dat[k*2+2];
//    }
//}
//
////[a,b)の間を[l,r]区間で比較しアップデート
////引数のindexに注意
////nは固定。initで計算すみ
////update2(L[i],R[i]+1,0,0,n,D[i]);
//void update2(int a,int b,int k,int l,int r,int v){//v更新値、区間は0-index
//    if(r<=a || b<=l)return;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=v*(r-l);
//        return;
//    }else{
//        update2(a,b,k*2+1,l,(l+r)/2,v);
//        update2(a,b,k*2+2,(l+r)/2,r,v);
//        return;
//    }
//}
//
//int query(int a,int b,int k,int l,int r){
//    if(r<=a || b<=l)return 0;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=0;
//        return dat[k];
//    }
//    else{
//        int vl=query(a,b,k*2+1,l,(l+r)/2);
//        int vr=query(a,b,k*2+2,(l+r)/2,r);
//        return vl+vr;
//    }
//}





ll dp[3001][3001];//jからi個並んでいる時のX-Y最大
ll dp2[3001][3001];//jからi個並んでいる時のX-Y最小
int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("3.txt");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >>N;
    ll a[100000];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    if(N==1){
        cout << a[0] << endl;
        return 0;
    }
    if(N==2){
        if(a[0]<a[1]){
            swap(a[0],a[1]);
        }
        cout << a[0]-a[1] << endl;
        return 0;
    }
    for(int j=0;j<N-2;j++){//3個ある時の取り方
        if(a[j]>a[j+2]){
            if(a[j+1]>a[j+2]){
                dp[3][j]=a[j]+a[j+2]-a[j+1];
            }else{
                dp[3][j]=a[j]+a[j+1]-a[j+2];
            }
        }else{
            if(a[j]>a[j+1]){
                dp[3][j]=a[j+2]+a[j+1]-a[j];
            }else{
                dp[3][j]=a[j+2]+a[j]-a[j+1];
            }
        }
        if(a[j]>a[j+2]){
            if(a[j+1]>a[j+2]){
                dp2[3][j]=a[j+1]-a[j]-a[j+2];
            }else{
                dp2[3][j]=a[j+2]-a[j]-a[j+1];
            }
        }else{
            if(a[j]>a[j+1]){
                dp2[3][j]=a[j]-a[j+2]-a[j+1];
            }else{
                dp2[3][j]=a[j+1]-a[j+2]-a[j];
            }
        }
    }
    for(int i=4;i<=N;i++){
        for(int j=0;j<N-(i-1);j++){
            if(a[j]+dp2[i-1][j+1]>a[j+(i-1)]+dp2[i-1][j]){
                dp[i][j]=a[j]+dp2[i-1][j+1];
            }else{
                dp[i][j]=a[j+(i-1)]+dp2[i-1][j];
            }
            if(dp[i-1][j+1]-a[j]>dp[i-1][j]-a[j+(i-1)]){
                dp2[i][j]=dp[i-1][j]-a[j+(i-1)];
            }else{
                dp2[i][j]=dp[i-1][j+1]-a[j];
            }
        }
    }
    cout << dp[N][0] << endl;
    
    //ここまで
    //cout << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
