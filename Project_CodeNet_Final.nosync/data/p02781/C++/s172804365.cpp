#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int combination(int N, int c){
    int temp=1;
    for(int i=0;i<c;i++){
        temp = temp*(N-i);
    }
    for(int i=0;i<c;i++){
        temp = temp/(1+i);
    }
    return temp;
}

signed main(){
    string N;
    int K;
    cin>>N;
    cin>>K; 

    int len = N.size();

    if(len<K){
        cout<<0<<endl;
        return 0;
    }    
    int index=0;

    for(int i=K;i<len;i++){
        index+= combination(i-1, K-1)*pow(9,K);
    }
//    index+= (combination(len-1, K-1)-1)*
    if(K==1){
        index+=charToInt(N.at(0));
    }else if(K==2){
        index += ((len-1)*9)*(charToInt(N.at(0))-1);
        int tt=1;
        while(tt<len){
            if(charToInt(N.at(tt))!=0){
                break;
            }
            tt++;
        }
        if(tt<len){
            index += ((len-tt-1)*9 + charToInt(N.at(tt)));
        }
    }else{
        index += ((len-1)*(len-2)*9*9/2)*(charToInt(N.at(0))-1); //最上位桁が最大値でない
        int tt1=1;
        while(tt1<len-1){
            if(charToInt(N.at(tt1))!=0){
                break;
            }
            tt1++;
        }

        if(tt1<len-1){
            index += ((len-tt1-1)*9)*(charToInt(N.at(tt1))-1) + (len-tt1-1)*(len-tt1-2)/2*9*9; // 最上位けたが最大値かつ2桁目が最大値でない

            int tt2=tt1+1;
            while(tt2<len){
             if(charToInt(N.at(tt2))!=0){
                break;
                }
            tt2++;
            }

        if(tt2<len){
            index += ((len-tt2-1)*9 + charToInt(N.at(tt2)));
        }

        }
    }

    cout<<index<<endl;


    return 0;
}