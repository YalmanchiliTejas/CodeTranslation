#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <regex> //正規表現
#include <map>
#include <set>
#include <cassert> //assart
#include <numeric>
#include <iterator>
#include <list>

using namespace std;
#define ll long long int
#define FOR(i,min,max) for(int i=(min);i<(max);i++)
#define FOReq(i,min,max) for(int i=(min);i<=(max);i++)
#define FORREV(i,max,min) for(int i=(max)-1;i>=(min);i--)
#define FORREVeq(i,max,min) for(int i=(max);i>=(min);i--)
const int  MOD=1e9+7;
const int  INF=2000000000;
const int INF2=  10000000;
const double  Micro=1e-5;

int UnUsedVariable(){
    if(INF || Micro || MOD || INF2){;}
    return 0;
}

#define pf printf
#define sf scanf
#define inarray(array,min,max) FOR(i,min,max){cin>>array[i];}
#define inarrayW(arrayA,arrayB,min,max) FOR(i,min,max){cin>>arrayA[i]>>arrayB[i];}
#define br printf("\n");
#define OutputAndReturn0(x) {cout<<(x)<<endl;return 0;}

#define issame(a,b,c,d) ((a)==(b) and (b)==(c) and (c)==(d))
#define isdiff3(a,b,c) ((a)!=(b) and (b)!=(c) and (c)!=(a))
#define isdiff4(a,b,c,d) ((a)!=(b) and (b)!=(c) and (c)!=(a) and (d)!=(a) and (d)!=(b) and (d)!=(c))
inline int isEven(int x){return x%2==0;}
inline int isOdd (int x){return x%2==1;}
inline ll  gcd(ll a,ll b){ if(b==0)return a;else return gcd(b,a%b);}//最大公約数 なお一方が0なら答えは他方になるので番兵は０で良い また、負の数もOK -4%3=-1となるため
inline ll  lcm(ll a,ll b){return a*b/gcd(a,b);}//MODやオーバーフローには注意！



//Eと名のつくのはデバッグ用！
int EintN(int array[],const int num){
    for(int i=0;i<num;i++){cerr<<array[i]<<" ";}
    br;
    return 0;
}
int EintNN(const int heighth,const int width,int array[heighth][width]){
    FOR(i, 0, heighth){
        FOR(k, 0, width){
            {cerr<<array[i][k]<<" ";}
        }
        br;
    }
    br;
    return 0;
}
int Eint(string str,const int num){
    cerr<<str<<" is "<<num<<" now."<<endl;
    return 0;
}


int AllElementChange0(int array[],const int num){
    for(int i=0;i<num;i++){array[i]=0;}
    return 0;
}


int test(){
    return 0;
}

int Ap(){
    int ans;ans=0;
    int a;
    cin>>a;
    
    OutputAndReturn0(a*a*3);
    return 0;
}

int Bp(){
    int ans;ans=0;
    int N,D;
    cin>>N>>D;
    OutputAndReturn0((N+2*D)/(2*D+1));
    return 0;
}

int Cp(){
    int ans;ans=0;
    int N;cin>>N;
    int A[N+1];
    AllElementChange0(A, N+1);
    int max1=0,max2=0;
    FOReq(i, 1, N){
        cin>>A[i];
        
        if(max1<=A[i]){max2=max1;max1=A[i];}
        else if(max2<=A[i]){max2=A[i];}
        
    }
    
    FOR(i, 1, N+1){
        cout<< ((A[i]==max1)?max2:max1) <<endl;
    }
   
    //OutputAndReturn0(ans);
    return 0;
}

int Dp(){
    int ans;ans=0;
    int N;cin>>N;
    int a[N+1];
    AllElementChange0(a, N+1);
    FOReq(i, 1, N){
        cin>>a[i];
    }
    
    int isball[N+1];AllElementChange0(isball, N+1);
    
    int sumofballs=0;
    
    FORREVeq(i, N, 1){
        if(i>N/2 +1){isball[i]=a[i];if(isball[i]==1){sumofballs++;}continue;}
        
        int existballs=0;
        for(int k=2*i;k<=N;k+=i){
            if(isball[k])existballs++;
        }
        if(existballs%2!=a[i]){isball[i]=1;sumofballs++;}
        else isball[i]=0;
        
    }
    
    cout <<sumofballs<<endl;
    FOReq(i, 1, N){
        if(isball[i])cout<<i<<" ";
    }
    br;
    
    //OutputAndReturn0(ans);
    return 0;
}

int Ep(){
    int ans;ans=0;
    int N;cin>>N;
    
    int EachColorMaxNum[N];
    FOR(i, 0, N){
        EachColorMaxNum[i]=-1;
    }
    
    int A[N];
    AllElementChange0(A, N);
    
    int NotIncreaseNum=0;
    FOR(i, 0, N){
        cin>>A[i];
        //if(i>=1){
        //    if(A[i-1]>=A[i])NotIncreaseNum++;
        //}
    }
    
    //入力と初期化完了！
    //if(NotIncreaseNum+1==N){OutputAndReturn0(N);}
    
    bool BeforeIsUpdate=false;
    FOR(i, 0, N){
        if(BeforeIsUpdate && A[i-1]>=A[i]){EachColorMaxNum[ans]=A[i];ans++;BeforeIsUpdate=true ;continue;}
        FOReq(k, 0, ans){
            if(k==ans)         {EachColorMaxNum[ans]=A[i];ans++;BeforeIsUpdate=true ;break;}
            if(A[i]>EachColorMaxNum[k]){EachColorMaxNum[k]=A[i];BeforeIsUpdate=false;break;}
        }
        //if(NotIncreaseNum+1==ans){OutputAndReturn0(ans);}
    }
    
    
    
    OutputAndReturn0(ans);
    return 0;
}

signed main(){
    //test();
    //Ap();
    //Bp();
    //Cp();
    //Dp();
    Ep();
    return 0;
}
