#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
#include<set>
#include <stdexcept>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
typedef long long ll;
int ceil(int a,int b){// a以上でbの倍数の最小値を出力//
    return (a+b-1)/b*b;
}

//シフト演算　(1<<k) 2のk乗

int stoii(string s){//stoi関数の代用 文字列を数値として読み取りint型に変換//
    return atoi(s.c_str());
}
int main (void){
    string s;
    s="t";
    vector<int> v(32,0);
    vector<int> c(300000,500);
    int j=0;

    while(s!="#"){
        cin>>s;
        if(s=="#") break;
        rep(i,s.size()){
                if(s[i]=='y'||s[i]=='u'||s[i]=='o'||
                s[i]=='i'||s[i]=='p'||s[i]=='h'||s[i]=='j'
                ||s[i]=='k'||s[i]=='l'||s[i]=='n'||s[i]=='m'
                ){
                    v[i]=1;
                }    
                else{
                    v[i]=0;
                }    
        }
        int cnt=0;
        rep(i,s.size()-1){
            if(v[i]!=v[i+1]) cnt++;
        }
        c[j]=cnt;
        j++;
    }
    int f=0;
    while(f!=j){
        cout<<c[f]<<endl;
        f++;
    } 
}
